#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

typedef struct point {
	int x;
	int y;
} point_t;

typedef struct point_array {
	point_t * points;
	int size;
} point_array_t;

typedef struct output {
	char * output_text;
	int width;
	int height;
} output_t;

int drawPoint(const int x, const int y, output_t * out) {
	out->output_text[(out->width + 1) * y + x] = '*';
	return 0;
}

int setBeginEnd(const int a, const int b, int * const begin, int * const end) {
	if (a < b) {
		*begin = a;
		*end = b;
		return 0;
	}
	else {
		*begin = b;
		*end = a;
		return 1;
	}
}

// 直線を描画　
int draw(point_t * p1, point_t * p2, output_t * out) {
	int x, y, begin, end, d_x, d_y, d;
	double deltaError;
	double error = 0.0f;
	if (p1->x == p2->x) {
		setBeginEnd(p1->y, p2->y, &begin, &end);
		x = p1->x;
		y = begin;
		do {
			drawPoint(x, y, out);
		} while (y++ != end);
	}
	else if (p1->y == p2->y) {
		setBeginEnd(p1->x, p2->x, &begin, &end);
		x = begin;
		y = p1->y;
		do {
			drawPoint(x, y, out);
		} while (x++ != end);
	}
	else {

		// プレゼンハムのアルゴリズム
		d_x = p2->x - p1->x;
		d_y = p2->y - p1->y;
		if (d_x >= d_y) {
			deltaError = fabs(d_y / d_x);
			y = p1->y;
			d = d_x / abs(d_x);
			for (x = p1->x; x != p2->x; x += d) {
				drawPoint(x, y, out);
				error += deltaError;
				if (error >= 0.5) {
					y += (p2->y - p1->y) / abs(p2->y - p1->y);
					error -= 1.0;
				}
			}
		}
		else {
			deltaError = fabs(d_x / d_y);
			x = p1->x;
			d = d_y / abs(d_y);
			for (y = p1->y; y != p2->y; y += d) {
				drawPoint(x, y, out);
				error += deltaError;
				if (error >= 0.5f) {
					x += (p2->x - p1->x) / abs(p2->x - p1->x);
					error -= 1.0f;
				}
			}
		}
	}
	return 0;
}

int show(point_array_t * point_array) {
	int i, j, size;
	point_t * points = point_array->points;
	output_t out;

	// 大きさを計算
	out.width = points[0].x;
	out.height = points[0].y;
	for (i = 1, size = point_array->size; i != size; ++i) {
		if (points[i].x + 1 > out.width) {
			out.width = points[i].x + 1;
		}
		if (points[i].y + 1> out.height) {
			out.height = points[i].y + 1;
		}
	}

	// メモリを確保
	if ((out.output_text = (char *)malloc(((out.width + 1) * out.height + 1) * sizeof(char))) == NULL) {
		printf("Cannot allocate memory\n");
		return 1;
	}

	// 文字列をスペースで初期化
	for (i = 0; i != out.height; ++i) {
		for (j = 0; j != out.width; ++j) {
			out.output_text[i * (out.width + 1) + j] = ' ';
		}
		out.output_text[i * (out.width + 1) + out.width] = '\n';
	}
	out.output_text[(out.width + 1) * out.height] = '\0';

	// 直線を描画
	for (i = 0; i != point_array->size - 1; ++i) {
		draw(points + i, points + i + 1, &out);
	}
	// 始点と終点を結ぶ直線を描画
	draw(points + point_array->size - 1, points, &out);
	printf("%s\n", out.output_text);
	free(out.output_text);
	return 0;
}

int main() {
	int i;
	point_array_t array;
	point_t * points;
	if ((array.points = malloc(10 * sizeof(point_t))) == NULL) {
		printf("メモリを確保できません\n");
		return 1;
	}
	points = array.points;
	printf("頂点の座標を整数で入力してください(最大10)\n入力を終了したい場合は同じ点を入力してください\n");
	for (i = 0; i != 10; ++i) {
		printf("[%d]x:", i);
		scanf("%d", &points[i].x);
		printf("[%d]y:", i);
		scanf("%d", &points[i].y);
		if (i > 0 && points[0].x == points[i].x && points[0].y == points[i].y) {
			break;
		}
	}
	array.size = i;
	if (show(&array)) {
		return 1;
	}
	free(array.points);
	return 0;
}

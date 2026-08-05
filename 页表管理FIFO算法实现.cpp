#include <iostream>
#include <queue>

using std::cout;
using std::cin;
using std::queue;

static bool inFrame(queue<int> frame,int value) {
	for (int i = 0; i < frame.size(); ++i) {
		if (value == frame.front()) {
			return true;
		}
		frame.pop();
	}
	return false;
}

/* page：依次访问的请求页
 * frame_size：储存页的大小
 */

int FIFO(int *page, int page_size, int frame_size) {
	int lack = 0;	// 缺页数量
	queue<int> frame;

	// 依次处理请求页
	for (int i = 0; i < page_size; ++i) {
		// 未找到的情况
		if (inFrame(frame, page[i]) == false) {
			++lack;
			// 已满
			if (frame.size() == frame_size) {
				frame.pop();
				frame.push(page[i]);
			}
			else {
				frame.push(page[i]);
			}
		}
	}

	return lack;
}

int pages[] = { 7,0,1,2,0,
				3,9,3,4,6,
				2,3,4,6 };

int main() {
	cout << FIFO(pages, 14, 3);
}
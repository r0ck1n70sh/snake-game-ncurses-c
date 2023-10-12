#include <unistd.h>
#include <render/screen_render.h>


static long to_us(long interval) {
	return 1000L * interval;
}

void render(int (* callback)(), long interval_in_ms) {
	int callback_code = 0;
	long interval = to_us(interval_in_ms);

	while (callback_code == 0) {
		callback_code = callback();
		usleep(interval);
	}
}

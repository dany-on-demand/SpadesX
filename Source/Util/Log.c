#include <stdarg.h>
#include <stdio.h>
#include <time.h>

void printfWithTime(const char *format, ...) {
	time_t t = time(NULL);
	struct tm *tm = localtime(&t);
	char s[64];
    size_t ret = strftime(s, sizeof(s), "%d/%m %H:%M:%S", tm);
	if (ret == 0) {
		return;
	}
	va_list args;
    va_start(args, format);
    char fMessage[1024];
    vsnprintf(fMessage, 1024, format, args);
    va_end(args);
	printf("\x1B[38;2;210;10;200m%s\x1B[0;37m %s", s, fMessage);
}
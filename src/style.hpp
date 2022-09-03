#ifndef _STYLE_HPP_
#define _STYLE_HPP_

#define CLEAR "\033[2J\033[1;1H"
#define CLEAR_LAST "\033[1A\033[2K"
#define RESET "\033[0m"

#define NEWLINE "\n"

/*format*/
#define UNDERLINE "\033[4m"
#define REVERSE "\033[7m"
#define HIDE "\033[8m"
#define STRIKE "\033[9m"

#define NO_UNDERLINE "\033[24m"
#define NO_REVERSE "\033[27m"
#define NO_HIDE "\033[28m"
#define NO_STRIKE "\033[29m"

/*foreground color*/
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#define BOLD "\033[1m"
#define BOLD_RED "\033[1;31m"
#define BOLD_GREEN "\033[1;32m"
#define BOLD_YELLOW "\033[1;33m"
#define BOLD_BLUE "\033[1;34m"
#define BOLD_MAGENTA "\033[1;35m"
#define BOLD_CYAN "\033[1;36m"
#define BOLD_WHITE "\033[1;37m"
#define BOLD_BLACK "\033[1;30m"

/*background color*/
#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"

#endif // _STYLE_HPP_
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int main (int argc, char** argv) {
    if (argc < 2) {
        printf ("Usage: %s <brainfuck-file-name>\n", argv[0]);
        return 0;
    }

    char* file_arg = argv[argc - 1];

    bool strict = false;

    for (int i = 1; i < argc; ++i) {
        if (!strcmp(argv[i], "-s") || !strcmp(argv[i], "--strict")) {
            strict = true;
        }
    }

    stack<fpos_t> loop_stack;

    const size_t CELLS_LEN = 30000;
    char cells[CELLS_LEN] = {0};
    size_t jump_to = 0;
    size_t pos = 0;

    int ch, ch_last;
    fpos_t tmp;
    FILE* file = fopen (file_arg, "r");
    if (file == NULL) {
        printf ("Unable to open the file: %s\n", argv[1]);
        return -1;
    }

    do {
        ch = fgetc (file);
        if (!jump_to && ch == '[') {
            fgetpos (file, &tmp);
            loop_stack.push (tmp);
        }

        switch (ch) {
            case '<':
                if (!jump_to) {
                    pos = --pos % CELLS_LEN;
                }
                break;

            case '>':
                if (!jump_to) {
                    pos = ++pos % CELLS_LEN;
                }
                break;

            case '+':
                if (!jump_to) {
                    ++cells[pos];
                }
                break;

            case '-':
                if (!jump_to) {
                    --cells[pos];
                }
                break;

            case '.':
                if (!jump_to) {
                    putchar (cells[pos]);
                }
                break;

            case ',':
                if (!jump_to) {
                    cells[pos] = getchar ();
                }
                break;

            case '[':
                if (!cells[pos] || jump_to) {
                    ++jump_to;
                }
                break;

            case ']':
                if (jump_to) {
                    --jump_to;
                } else if (!cells[pos]) {
                    loop_stack.pop ();
                } else {
                    fsetpos (file, &loop_stack.top ());
                }
                break;
         }

         //--- the following commands are part of the language extension ---//
         if (!strict) {
             switch (ch) {
                case '!':
                    if (!jump_to) {
                        cells[pos] = 0;
                    }
                    break;

                case '&':
                    if (!jump_to) {
                        pos = ((int)cells[pos]) % CELLS_LEN;
                    }
                    break;

                case '?':
                    printf ("Index:%d Decimal:%d ASCII:%c\n", pos, (int) cells[pos], cells[pos]);
                    break;
            }
        }
        ch_last = ch;
    } while (!feof (file));
    fclose (file);
    return 0;
}

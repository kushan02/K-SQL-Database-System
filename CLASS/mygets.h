
char *mygets(char *buf)
{
        char *p = buf;
        int ch;

        while (1) {
                ch = getchar();
                if (ch == EOF) {
                        std::cout<<std::endl<<"EOF HERE"<<std::endl;
                        //    if (errno == ETIMEDOUT) continue;
                        return NULL;
                }

                if (ch == 8) {
                        if (p > buf) {
                                //  putchar('\b');
                                //  putchar(' ');
                                //    putchar('\b');
                                p--;
                        }
                } /*else if (ch == '\r' || ch =='\n' || ch >= ' ') {
                        putchar(ch);
                        if (ch == '\r') putchar('\n');
                        if (ch == '\n' || ch == '\r') break;
                   * p++ = ch;
                   */
                else  {
                        //    putchar(ch);
                        //    if (ch == '\r') putchar('\n');
                        //  if (ch == '\n' || ch == '\r') ;
                        if (ch ==';')
                        {
                                std::cout<<std::endl<<"SEMI COLON FOUND";
                                break;
                        }
                        else
                        {
                                std::cout << '\n'<< " -> ";
                        }
                        *p++ = ch;
                }
        }

        *p = 0;
        return buf;
}

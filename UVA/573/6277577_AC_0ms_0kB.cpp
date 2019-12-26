#include <stdio.h>

int main()
{
    float h, u, d, f, dst_clmbd, h8_af_clmbng, h8_af_sldng;
    int i;

    while (scanf("%f %f %f %f", &h, &u, &d, &f) == 4) {
        if (h == 0) break;
        if(u>h){printf("success on day 1\n");continue;}
        f = f / 100;
        dst_clmbd = u;
        h8_af_clmbng = u;
        h8_af_sldng = h8_af_clmbng - d;

        for (i = 2; ; ++i) {
            dst_clmbd = dst_clmbd - (u * f);

            if (dst_clmbd < 0) dst_clmbd = 0;
            h8_af_clmbng = dst_clmbd + h8_af_sldng;

            if (h8_af_clmbng > h) {
                printf("success on day %d\n", i);
                break;
            }

                else if (h8_af_sldng < 0) {
                    printf("failure on day %d\n", i - 1);
                    break;
                }

            h8_af_sldng = h8_af_clmbng - d;
        }
    }

    return 0;
}

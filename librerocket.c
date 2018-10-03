#include <stdio.h>
#include <math.h>

int main()
{
    /*
     *This program is free software: you can redistribute it and/or modify
     *it under the terms of the GNU General Public License as published by
     *the Free Software Foundation, either version 3 of the License, or
     *(at your option) any later version.
     *
     *This program is distributed in the hope that it will be useful,
     *but WITHOUT ANY WARRANTY; without even the implied warranty of
     *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     *GNU General Public License for more details.
     *
     *You should have received a copy of the GNU General Public License
     *along with this program.  If not, see <https://www.gnu.org/licenses/gpl-3.0.en.html.
     */

    float nconel;
    float d;
    float df;
    float dr;
    float lt;
    float xp;
    float cr;
    float ct;
    float s;
    float lf;
    float r;
    float xr;
    float xb;
    float n;
    float xn;
    float cnt;
    float xt;

    printf("Welcome to librerocket 0.1.  This program has not been thoughly debugged and is\n");
    printf("therefore not suitable as a stability calculator unless you check the results\n");
    printf("against a known good stability calculator or other rocket cad program which\n");
    printf("calculates stability.  Currently we only support millimeters.\n");
    printf("Is the nose cone shape a cone (c) or ogive (o)?\n");
    int ncone = getchar();
    printf("please type the nose cone length.\n");
    scanf(" %f", &nconel);
    if (ncone == 99) {
        xn = 0.666 * nconel;
    } else if (ncone == 111) {
	xn = 0.466 * nconel;
    } else {
	printf("invalid nose cone shape or program bug\n");
    }
    printf("please type the base diameter of the nose cone.\n");
    scanf(" %f", &d);
    printf("Is there a conical transition before the fins(y\\n)?\n");
    getchar();
    int conet = getchar();
    if (conet == 121)
    {
	printf("please enter the diameter of the front of the transition.\n");
	scanf(" %f", &df);
	printf("please enter the diameter at the rear of the transistion.\n");
	scanf(" %f", &dr);
	printf("please enter the length of the transistion.\n");
	scanf(" %f", &lt);
	printf("please enter the distance from the tip of the nose cone to the front of\n");
	printf("the transistion.\n");
	scanf(" %f", &xp);
	cnt = 2*((dr/d)*(dr/d)-(df/d)*(df/d));
	xt = xp + lt/3*(1+(1-df/dr)/(1-(df/dr)*(df/dr)));
    } else if (conet == 110)
    {
	printf("Ok, no transistion.\n");
    } else
    {
	printf("It is case sensitive but it could be a bug.\n");
    }
    printf("please enter fin root chord.\n");
    scanf(" %f", &cr);
    printf("please enter fin tip chord.\n");
    scanf(" %f", &ct);
    printf("please enter fin semispan.\n");
    scanf(" %f", &s);
    printf("please enter length from center of root chord to center of tip chord\n");
    scanf(" %f", &lf);
    printf("please enter radius of rocket body at aft end.\n");
    scanf(" %f", &r);
    printf("please enter the distance between fin root leading edge and fin tip leading\n");
    printf("edge parallel to the rocket body.\n");
    scanf(" %f", &xr);
    printf("please enter the distance from nose cone tip to fin root chord leading edge.\n");
    scanf(" %f", &xb);
    printf("please enter the number of fins.\n");
    scanf(" %f", &n);
    float squart = sqrtf(1+((2*lf)/(cr+ct))*((2*lf)/(cr+ct)));
    float cnf = (1+r/(s+r))*((4*n*((s/d)*(s/d)))/(1+squart));
    float xf = xb+(xr*(cr+(2*ct)))/(3*(cr+ct))+(1/6*((cr+ct)-(cr*ct)/cr+ct));
    float cnr = 2+cnt+cnf;
    float x = (2*xn+cnt*xt+cnf*xf)/cnr;
    printf("center of pressure is at %f millimeters from nose cone tip.\n", x);
    return 0;
}

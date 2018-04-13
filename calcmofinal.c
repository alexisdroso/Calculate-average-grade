#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inpects(void) ;
float inpvath(void) ;
float calcsynt(int ects);

int main(int argc, char *argv[]) {
	int ects;
	float vathmos,synt,sumvath,sumsynt=0;
	printf("\t\t\t\t\tGPA calculation for the ECE@UoP\n") ;
	for(;;){
        vathmos = inpvath() ;
        if (vathmos == 0) break ;
		ects = inpects() ;
        synt = calcsynt(ects);
        sumvath += vathmos * synt;
        sumsynt += synt;
    }
    if (sumsynt == 0) printf("\nYou didn't enter any course grade!\n\n") ;
    else printf("\nYour GPA is: %.2f\n\n",sumvath/sumsynt);
	system("pause") ;
	return 0;
}

int inpects(void) {
    char *end, s[4096];
    int ects,i,flag = 0;
    printf("\nPlease enter an integer positive ects grade: ");
    while (fgets(s, sizeof(s), stdin)){
        ects = strtol(s, &end, 10);
        for (i=0; i<strlen(s)-1; i++){
        	if (!isdigit(s[i]) && s[i]!='.' && s[i]!='-') {
        		flag = 1 ;
				break;	
			}
		}
		if (flag == 1){
			printf("Please enter the ects grade without any character: ") ;
			flag = 0 ;
		}
		else if (s[0] == '\n') {
            printf("Please enter a positive ects grade: ");
        }
        else if (strlen(end)-1 != 0 && ects<=0 ){
        	printf("Please enter an INTEGER POSITIVE ects grade: ");
		}
        else if (strlen(end)-1 !=0) {
            printf("Please enter an INTEGER positive ects grade: ");
        }
        else if (ects<=0) {
        	printf("Please enter an integer POSITIVE ects grade: ");
		}
		else break;
    }
    return ects;
}

float inpvath(void) {
	char s[4096],*cp;
	float vath,pollaplasio;
	int i;
    printf("\nPlease enter a course grade >= 5 or enter 0 to terminate the computation: ");
    while(fgets(s,sizeof(s),stdin)){
    	vath = strtod(s, &cp);
    	pollaplasio = vath/0.5 ;
    	if (s[0] == '\n') printf("Please enter a course grade >= 5 or enter 0 to terminate the computation: ");
		else if(strlen(cp)-1 == 0 && vath == 0) return vath;
		else if (strlen(cp)-1!=0) printf("Please enter a valid course grade without characters - {.} or enter 0 to terminate the computation:  ") ;
		else if (vath<5 || vath>10) printf("Please enter a course grade in the closed interval [5-10]: ") ;
		else if (pollaplasio - (int) pollaplasio != 0) printf("The course grade must be an integer multiple of 0.5: ") ;
		else break;
	}
    return vath ;
}

float calcsynt(int ects){
    float synt;
    if (ects<3) synt = 1;
    else if (ects<5) synt = 1.5;
    else synt = 2;
    return synt;
}

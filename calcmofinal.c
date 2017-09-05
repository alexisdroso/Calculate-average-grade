#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inpects(void) ;
float inpvath(void) ;
float calcsynt(int ects);

int main(int argc, char *argv[]) {
	system("chcp 1253"); system("cls") ;
	int ects;
	float vathmos,synt,sumvath,sumsynt=0;
	printf("\t\t\t\t\t\t ΥΠΟΛΟΓΙΣΜΟΣ ΜΟ ΗΜΤΥ\n") ;
	for(;;){
        vathmos = inpvath() ;
        if (vathmos == 0) break ;
		ects = inpects() ;
        synt = calcsynt(ects);
        sumvath += vathmos * synt;
        sumsynt += synt;
    }
    if (sumsynt == 0) printf("\nΔεν πληκτρολόγησες κανένα βαθμό!\n\n") ;
    else printf("\nΈχεις μέσο όρο: %.2f\n\n",sumvath/sumsynt);
	system("pause") ;
	return 0;
}

int inpects(void) {
    char *end, s[4096];
    int ects,i,flag = 0;
    printf("\nΠαρακαλώ πληκτρολόγησε έναν ακέραιο θετικό αριθμό ects: ");
    while (fgets(s, sizeof(s), stdin)){
        ects = strtol(s, &end, 10);
        for (i=0; i<strlen(s)-1; i++){
        	if (!isdigit(s[i]) && s[i]!='.' && s[i]!='-') {
        		flag = 1 ;
				break;	
			}
		}
		if (flag == 1){
			printf("Παρακαλώ πληκτρολόγησε τον αριθμό των ects χωρίς κάποιο χαρακτήρα: ") ;
			flag = 0 ;
		}
		else if (s[0] == '\n') {
            printf("Παρακαλώ πληκτρολόγησε κάποιον θετικό αριθμό ects: ");
        }
        else if (strlen(end)-1 != 0 && ects<=0 ){
        	printf("Παρακαλώ πληκτρολόγησε έναν ΑΚΕΡΑΙΟ ΘΕΤΙΚΟ αριθμό ects: ");
		}
        else if (strlen(end)-1 !=0) {
            printf("Παρακαλώ πληκτρολόγησε έναν ΑΚΕΡΑΙΟ θετικό αριθμό ects: ");
        }
        else if (ects<=0) {
        	printf("Παρακαλώ πληκτρολόγησε έναν ακέραιο ΘΕΤΙΚΟ αριθμό ects: ");
		}
		else break;
    }
    return ects;
}

float inpvath(void) {
	char s[4096],*cp;
	float vath,pollaplasio;
	int i;
    printf("\nΠαρακαλώ πληκτρολόγησε έναν βαθμό >= 5 ή το 0 για τον τερματισμό του υπολογισμού: ");
    while(fgets(s,sizeof(s),stdin)){
    	vath = strtod(s, &cp);
    	pollaplasio = vath/0.5 ;
    	if (s[0] == '\n') printf("Παρακαλώ πληκτρολόγησε έναν βαθμό >= 5 ή το 0 για τον τερματισμό του υπολογισμού: ");
		else if(strlen(cp)-1 == 0 && vath == 0) return vath;
		else if (strlen(cp)-1!=0) printf("Παρακαλώ πληκτρολόγησε έναν έγκυρο αριθμό χωρίς χαρακτήρες - {.} ή το 0 για τον τερματισμό του υπολογισμού: ") ;
		else if (vath<5 || vath>10) printf("Παρακαλώ πληκτρολόγησε έναν αριθμό στην κλίμακα [5-10]: ") ;
		else if (pollaplasio - (int) pollaplasio != 0) printf("Παρακαλώ ο βαθμός να είναι ακέραιο πολλαπλάσιο του 0.5: ") ;
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

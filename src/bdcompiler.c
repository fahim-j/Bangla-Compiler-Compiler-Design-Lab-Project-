// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <string.h>
// // #include <ctype.h>
// // #include <locale.h>
// // #ifdef _WIN32
// // #include <windows.h>
// // #endif

// // // ===================== UI FUNCTIONS =====================
// // void clearScreen() {
// // #ifdef _WIN32
// //     system("cls");
// // #else
// //     system("clear");
// // #endif
// // }

// // void color(const char *c) {
// //     printf("%s", c);
// // }

// // void banner() {
// //     color("\033[1;32m");
// //     printf("====================================\n");
// //     printf("      BD SCRIPT INTERPRETER v4.0\n");
// //     printf("====================================\n");
// //     color("\033[0m");
// // }

// // // ===================== HELPER FUNCTIONS =====================
// // int getVarIndex(char name[50][50], int count, const char *varname){
// //     for(int i=0;i<count;i++){
// //         if(strcmp(name[i],varname)==0) return i;
// //     }
// //     return -1;
// // }

// // int getVarValue(char name[50][50], int var[50], int count, const char *varname){
// //     int idx = getVarIndex(name, count, varname);
// //     if(idx != -1) return var[idx];
// //     return 0;
// // }

// // void setVarValue(char name[50][50], int var[50], int count, const char *varname, int value){
// //     int idx = getVarIndex(name,count,varname);
// //     if(idx!=-1) var[idx]=value;
// // }

// // // ===================== SCRIPT EXECUTION =====================
// // void run_script(const char *file) {
// //     FILE *fp = fopen(file, "r");
// //     if (!fp) {
// //         color("\033[1;31m");
// //         printf("Error: Cannot open script file!\n");
// //         color("\033[0m");
// //         return;
// //     }

// //     clearScreen();
// //     banner();
// //     printf("Running script: %s\n\n", file);

// //     char line[512];
// //     int var[50] = {0};
// //     char name[50][50];
// //     int count = 0;

// //     // For loop support: store loop start line
// //     char scriptLines[1024][512];
// //     int totalLines = 0;
// //     while(fgets(scriptLines[totalLines], sizeof(scriptLines[0]), fp)) totalLines++;
// //     fclose(fp);

// //     for(int lineNum=0; lineNum<totalLines; lineNum++){
// //         strcpy(line, scriptLines[lineNum]);
// //         char vname[50], text[200];
// //         int val;
// //         char a[50], b[50];
// //         char op;

// //         // ==================== সংখ্যা declaration ====================
// //         if (sscanf(line, "সংখ্যা %s %d", vname, &val) == 2) {
// //             strcpy(name[count], vname);
// //             var[count] = val;
// //             count++;
// //         }
// //         // ==================== সংখ্যা arithmetic declaration ====================
// //         else if (sscanf(line, "সংখ্যা %s %s %c %s", vname, a, &op, b) == 4) {
// //             int v1 = getVarValue(name,var,count,a);
// //             int v2 = getVarValue(name,var,count,b);
// //             int result=0;
// //             if(op=='+') result=v1+v2;
// //             else if(op=='-') result=v1-v2;
// //             else if(op=='*') result=v1*v2;
// //             else if(op=='/') result=(v2!=0)?v1/v2:0;
// //             strcpy(name[count],vname);
// //             var[count]=result;
// //             count++;
// //         }
// //         // ==================== লিখ command ====================
// //         else if (strncmp(line,"লিখ",4)==0){
// //             char *p=line+4;
// //             while(*p){
// //                 while(isspace(*p)) p++;
// //                 if(*p=='"'){
// //                     char msg[200];
// //                     p++; int i=0;
// //                     while(*p && *p!='"') msg[i++]=*p++;
// //                     msg[i]=0;
// //                     if(*p=='"') p++;
// //                     printf("%s",msg);
// //                 }
// //                 else if(isalpha(*p)){
// //                     char varname[50]; int i=0;
// //                     while(*p && !isspace(*p)) varname[i++]=*p++;
// //                     varname[i]=0;
// //                     int found=0;
// //                     for(int j=0;j<count;j++){
// //                         if(strcmp(name[j],varname)==0){
// //                             printf("%d",var[j]);
// //                             found=1; break;
// //                         }
// //                     }
// //                     if(!found) printf("%s",varname);
// //                 }
// //                 else p++;
// //             }
// //             printf("\n");
// //         }
// //         // ==================== যদি condition ====================
// //         else if(strstr(line,"যদি")!=NULL && strstr(line,"লিখ")!=NULL){
// //             char msg[200], op_str[3];
// //             sscanf(line,"যদি %s %s %s লিখ \"%[^\"]\"",a,op_str,b,msg);
// //             int v1=getVarValue(name,var,count,a);
// //             int v2=getVarValue(name,var,count,b);
// //             int cond=0;
// //             if(strcmp(op_str,"<")==0) cond=v1<v2;
// //             else if(strcmp(op_str,">")==0) cond=v1>v2;
// //             else if(strcmp(op_str,"==")==0) cond=v1==v2;
// //             else if(strcmp(op_str,"!=")==0) cond=v1!=v2;
// //             else if(strcmp(op_str,"<=")==0) cond=v1<=v2;
// //             else if(strcmp(op_str,">=")==0) cond=v1>=v2;
// //             if(cond) printf("%s\n",msg);
// //         }
// //         // ==================== simple assignment ====================
// //         else if(sscanf(line,"%s = %d",vname,&val)==2){
// //             setVarValue(name,var,count,vname,val);
// //         }
// //         // ==================== arithmetic assignment ====================
// //         else if(sscanf(line,"%s = %s %c %s",vname,a,&op,b)==4){
// //             int v1=getVarValue(name,var,count,a);
// //             int v2=getVarValue(name,var,count,b);
// //             int result=0;
// //             if(op=='+') result=v1+v2;
// //             else if(op=='-') result=v1-v2;
// //             else if(op=='*') result=v1*v2;
// //             else if(op=='/') result=(v2!=0)?v1/v2:0;
// //             setVarValue(name,var,count,vname,result);
// //         }
// //         // ==================== for-loop ====================
// //         else if(strncmp(line,"যাবত",4)==0){
// //             // Syntax: "যাবত i = 0 থেকে i < 10 পর্যন্ত"
// //             char loopVar[50]; int startVal=0; char condVar[50]; char cmp[3]; int cmpVal=0;
// //             sscanf(line,"যাবত %s = %d থেকে %s %s %d পর্যন্ত", loopVar, &startVal, condVar, cmp, &cmpVal);
// //             setVarValue(name,var,count,loopVar,startVal);

// //             int startLine = lineNum+1;
// //             int endLine = totalLines; // will search for “শেষ” keyword
// //             for(int l=lineNum+1;l<totalLines;l++){
// //                 if(strncmp(scriptLines[l],"শেষ",4)==0){
// //                     endLine=l; break;
// //                 }
// //             }

// //             while(1){
// //                 int loopVarVal=getVarValue(name,var,count,loopVar);
// //                 int conditionMet=0;
// //                 if(strcmp(cmp,"<")==0) conditionMet=loopVarVal<cmpVal;
// //                 else if(strcmp(cmp,">")==0) conditionMet=loopVarVal>cmpVal;
// //                 else if(strcmp(cmp,"<=")==0) conditionMet=loopVarVal<=cmpVal;
// //                 else if(strcmp(cmp,">=")==0) conditionMet=loopVarVal>=cmpVal;
// //                 else if(strcmp(cmp,"==")==0) conditionMet=loopVarVal==cmpVal;
// //                 else if(strcmp(cmp,"!=")==0) conditionMet=loopVarVal!=cmpVal;

// //                 if(!conditionMet) break;

// //                 // execute loop block
// //                 for(int ln=startLine; ln<endLine; ln++){
// //                     strcpy(line, scriptLines[ln]);
// //                     // recursively execute line (basic reuse: assignment & print only)
// //                     if (strncmp(line,"লিখ",4)==0){
// //                         char *p=line+4;
// //                         while(*p){
// //                             while(isspace(*p)) p++;
// //                             if(*p=='"'){
// //                                 char msg[200];
// //                                 p++; int i=0;
// //                                 while(*p && *p!='"') msg[i++]=*p++;
// //                                 msg[i]=0;
// //                                 if(*p=='"') p++;
// //                                 printf("%s",msg);
// //                             }
// //                             else if(isalpha(*p)){
// //                                 char varname[50]; int i=0;
// //                                 while(*p && !isspace(*p)) varname[i++]=*p++;
// //                                 varname[i]=0;
// //                                 int idx=getVarIndex(name,count,varname);
// //                                 if(idx!=-1) printf("%d",var[idx]);
// //                             }
// //                             else p++;
// //                         }
// //                         printf("\n");
// //                     }
// //                     else if(sscanf(line,"%s = %d",vname,&val)==2){
// //                         setVarValue(name,var,count,vname,val);
// //                     }
// //                     else if(sscanf(line,"%s = %s %c %s",vname,a,&op,b)==4){
// //                         int v1=getVarValue(name,var,count,a);
// //                         int v2=getVarValue(name,var,count,b);
// //                         int result=0;
// //                         if(op=='+') result=v1+v2;
// //                         else if(op=='-') result=v1-v2;
// //                         else if(op=='*') result=v1*v2;
// //                         else if(op=='/') result=(v2!=0)?v1/v2:0;
// //                         setVarValue(name,var,count,vname,result);
// //                     }
// //                 }

// //                 // increment loop variable
// //                 int loopVal=getVarValue(name,var,count,loopVar);
// //                 setVarValue(name,var,count,loopVar,loopVal+1);
// //             }

// //             // skip to end of loop
// //             lineNum=endLine;
// //         }
// //         // ==================== while-loop ====================
// //         else if(strncmp(line,"যখন",6)==0){
// //             // Syntax: "যখন a < 10"
// //             char condVar[50]; char cmp[3]; int cmpVal;
// //             sscanf(line,"যখন %s %s %d", condVar, cmp, &cmpVal);

// //             int startLine=lineNum+1;
// //             int endLine=totalLines;
// //             for(int l=lineNum+1;l<totalLines;l++){
// //                 if(strncmp(scriptLines[l],"শেষ",4)==0){endLine=l; break;}
// //             }

// //             while(1){
// //                 int varVal=getVarValue(name,var,count,condVar);
// //                 int condMet=0;
// //                 if(strcmp(cmp,"<")==0) condMet=varVal<cmpVal;
// //                 else if(strcmp(cmp,">")==0) condMet=varVal>cmpVal;
// //                 else if(strcmp(cmp,"<=")==0) condMet=varVal<=cmpVal;
// //                 else if(strcmp(cmp,">=")==0) condMet=varVal>=cmpVal;
// //                 else if(strcmp(cmp,"==")==0) condMet=varVal==cmpVal;
// //                 else if(strcmp(cmp,"!=")==0) condMet=varVal!=cmpVal;

// //                 if(!condMet) break;

// //                 // execute block
// //                 for(int ln=startLine; ln<endLine; ln++){
// //                     strcpy(line, scriptLines[ln]);
// //                     if (strncmp(line,"লিখ",4)==0){
// //                         char *p=line+4;
// //                         while(*p){
// //                             while(isspace(*p)) p++;
// //                             if(*p=='"'){
// //                                 char msg[200];
// //                                 p++; int i=0;
// //                                 while(*p && *p!='"') msg[i++]=*p++;
// //                                 msg[i]=0;
// //                                 if(*p=='"') p++;
// //                                 printf("%s",msg);
// //                             }
// //                             else if(isalpha(*p)){
// //                                 char varname[50]; int i=0;
// //                                 while(*p && !isspace(*p)) varname[i++]=*p++;
// //                                 varname[i]=0;
// //                                 int idx=getVarIndex(name,count,varname);
// //                                 if(idx!=-1) printf("%d",var[idx]);
// //                             }
// //                             else p++;
// //                         }
// //                         printf("\n");
// //                     }
// //                     else if(sscanf(line,"%s = %d",vname,&val)==2){
// //                         setVarValue(name,var,count,vname,val);
// //                     }
// //                     else if(sscanf(line,"%s = %s %c %s",vname,a,&op,b)==4){
// //                         int v1=getVarValue(name,var,count,a);
// //                         int v2=getVarValue(name,var,count,b);
// //                         int result=0;
// //                         if(op=='+') result=v1+v2;
// //                         else if(op=='-') result=v1-v2;
// //                         else if(op=='*') result=v1*v2;
// //                         else if(op=='/') result=(v2!=0)?v1/v2:0;
// //                         setVarValue(name,var,count,vname,result);
// //                     }
// //                 }
// //             }

// //             // skip to end of while
// //             lineNum=endLine;
// //         }

// //     } // end of main for loop

// //     color("\033[1;32m");
// //     printf("\nScript finished successfully.\n");
// //     color("\033[0m");
// // }

// // // ===================== MENU FUNCTIONS =====================
// // void help(){
// //     clearScreen();
// //     banner();
// //     color("\033[1;33m");
// //     printf("Bangla Script Syntax Help:\n\n");
// //     color("\033[0m");
// //     printf("1) Variable: সংখ্যা x 5\n");
// //     printf("2) Print: লিখ \"Hello\" or লিখ x or লিখ \"a = \" লিখ a\n");
// //     printf("3) If condition: যদি a < b লিখ \"a small\"\n");
// //     printf("4) Assignment: a = 10\n");
// //     printf("5) Arithmetic: a = b + c , a = b - c , a = b * c , a = b / c\n");
// //     printf("6) For loop: যাবত i = 0 থেকে i < 10 পর্যন্ত ... শেষ\n");
// //     printf("7) While loop: যখন a < 5 ... শেষ\n\n");
// //     printf("Press ENTER to return...");
// //     getchar();
// // }

// // void open_editor(){
// //     clearScreen();
// //     banner();
// //     printf("Opening script editor...\n");
// // #ifdef _WIN32
// //     system("notepad.exe");
// // #else
// //     system("nano");
// // #endif
// //     printf("\nPress ENTER to continue...");
// //     getchar();
// // }

// // void menu(){
// //     clearScreen();
// //     banner();
// //     color("\033[1;36m");
// //     printf("1. Run Script File\n");
// //     printf("2. Open Script Editor\n");
// //     printf("3. Help\n");
// //     printf("4. Exit\n");
// //     color("\033[0m");
// //     printf("\nChoose option: ");
// // }

// // // ===================== LANGUAGE SELECTION =====================
// // int language_selection(){
// //     int lang;
// //     clearScreen();
// //     banner();
// //     printf("Select Language:\n");
// //     printf("1. Bangla\n");
// //     printf("2. C (Coming Soon)\n");
// //     printf("3. C++ (Coming Soon)\n");
// //     printf("\nEnter choice: ");
// //     scanf("%d",&lang);
// //     getchar();
// //     return lang;
// // }

// // // ==================== MAIN =====================
// // int main()
// // {
// // #ifdef _WIN32
// //     system("chcp 65001 > nul");
// //     SetConsoleOutputCP(CP_UTF8);
// // #endif
// //     setlocale(LC_ALL, "bn_BD.utf8");

// //     int lang=language_selection();

// //     if(lang==1){
// //         int choice;
// //         char file[200];
// //         while(1){
// //             menu();
// //             scanf("%d",&choice);
// //             getchar();
// //             switch(choice){
// //                 case 1:
// //                     printf("Enter script filename: ");
// //                     fgets(file,sizeof(file),stdin);
// //                     file[strcspn(file,"\n")]=0;
// //                     run_script(file);
// //                     printf("\nPress ENTER to continue...");
// //                     getchar();
// //                     break;
// //                 case 2:
// //                     open_editor();
// //                     break;
// //                 case 3:
// //                     help();
// //                     break;
// //                 case 4:
// //                     clearScreen();
// //                     printf("Goodbye!\n");
// //                     return 0;
// //                 default:
// //                     printf("Invalid option!\n");
// //             }
// //         }
// //     }
// //     else if(lang==2){
// //         clearScreen();
// //         printf("C language IDE not implemented yet!\n");
// //     }
// //     else if(lang==3){
// //         clearScreen();
// //         printf("C++ language IDE not implemented yet!\n");
// //     }
// //     else{
// //         clearScreen();
// //         printf("Invalid language selection!\n");
// //     }

// //     return 0;
// // }













#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#ifdef _WIN32
#include <windows.h>
#endif

// ===================== UI FUNCTIONS =====================
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void color(const char *c) {
    printf("%s", c);
}

void banner() {
    color("\033[1;32m");
    printf("====================================\n");
    printf("      BD SCRIPT INTERPRETER v4.1\n");
    printf("====================================\n");
    color("\033[0m");
}

// ===================== HELPER FUNCTIONS =====================
int getVarIndex(char name[50][50], int count, const char *varname){
    for(int i=0;i<count;i++){
        if(strcmp(name[i],varname)==0) return i;
    }
    return -1;
}

int getVarValue(char name[50][50], int var[50], int count, const char *varname){
    int idx = getVarIndex(name, count, varname);
    if(idx != -1) return var[idx];
    return 0;
}

void setVarValue(char name[50][50], int var[50], int count, const char *varname, int value){
    int idx = getVarIndex(name,count,varname);
    if(idx!=-1) var[idx]=value;
}

// ===================== TRIM FUNCTION =====================
void trim(char *str) {
    if (!str) return;
    
    int start = 0;
    while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n' || str[start] == '\r') {
        start++;
    }
    
    if (start > 0) {
        int i = 0;
        while (str[start] != '\0') {
            str[i++] = str[start++];
        }
        str[i] = '\0';
    }
    
    int end = strlen(str) - 1;
    while (end >= 0 && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n' || str[end] == '\r')) {
        str[end--] = '\0';
    }
}

// ===================== SCRIPT EXECUTION =====================
void run_script(const char *file) {
    FILE *fp = fopen(file, "r");
    if (!fp) {
        color("\033[1;31m");
        printf("Error: Cannot open script file!\n");
        color("\033[0m");
        return;
    }

    clearScreen();
    banner();
    printf("Running script: %s\n\n", file);

    char line[512];
    int var[50] = {0};
    char name[50][50];
    int count = 0;

    char scriptLines[1024][512];
    int totalLines = 0;
    while(fgets(scriptLines[totalLines], sizeof(scriptLines[0]), fp)) totalLines++;
    fclose(fp);

    for(int lineNum=0; lineNum<totalLines; lineNum++){
        strcpy(line, scriptLines[lineNum]);
        trim(line);
        if(strlen(line) == 0) continue;
        
        char vname[50], text[200];
        int val;
        char a[50], b[50];
        char op;

        // ==================== নাও (user input) ====================
        if (sscanf(line, "নাও %s", vname) == 1) {
            int temp;
            printf("%s এর মান দিন: ", vname);
            scanf("%d", &temp);
            getchar();

            int idx = getVarIndex(name, count, vname);
            if (idx == -1) {
                strcpy(name[count], vname);
                var[count] = temp;
                count++;
            } else {
                var[idx] = temp;
            }
        }
        // ==================== সংখ্যা declaration ====================
        else if (sscanf(line, "সংখ্যা %s %d", vname, &val) == 2) {
            int idx = getVarIndex(name, count, vname);
            if (idx == -1) {
                strcpy(name[count], vname);
                var[count] = val;
                count++;
            } else {
                var[idx] = val;
            }
        }
        // ==================== সংখ্যা arithmetic declaration ====================
        else if (sscanf(line, "সংখ্যা %s %s %c %s", vname, a, &op, b) == 4) {
            int v1 = getVarValue(name,var,count,a);
            int v2 = getVarValue(name,var,count,b);
            int result=0;
            if(op=='+') result=v1+v2;
            else if(op=='-') result=v1-v2;
            else if(op=='*') result=v1*v2;
            else if(op=='/') result=(v2!=0)?v1/v2:0;
            
            int idx = getVarIndex(name, count, vname);
            if (idx == -1) {
                strcpy(name[count], vname);
                var[count] = result;
                count++;
            } else {
                var[idx] = result;
            }
        }
        // ==================== লিখ command ====================
        else if (strncmp(line,"লিখ",4)==0){
            char *p=line+4;
            while(*p){
                while(isspace(*p)) p++;
                if(*p=='"'){
                    char msg[200];
                    p++; int i=0;
                    while(*p && *p!='"') msg[i++]=*p++;
                    msg[i]=0;
                    if(*p=='"') p++;
                    printf("%s",msg);
                }
                else if(isalpha(*p)){
                    char varname[50]; int i=0;
                    while(*p && !isspace(*p) && *p!='"') varname[i++]=*p++;
                    varname[i]=0;
                    int found=0;
                    for(int j=0;j<count;j++){
                        if(strcmp(name[j],varname)==0){
                            printf("%d",var[j]);
                            found=1; break;
                        }
                    }
                    if(!found) printf("%s",varname);
                }
                else p++;
            }
            printf("\n");
        }
        // ==================== যদি condition ====================
        else if(strstr(line,"যদি")!=NULL && strstr(line,"লিখ")!=NULL){
            char msg[200], op_str[3];
            sscanf(line,"যদি %s %s %s লিখ \"%[^\"]\"",a,op_str,b,msg);
            int v1=getVarValue(name,var,count,a);
            int v2=getVarValue(name,var,count,b);
            int cond=0;
            if(strcmp(op_str,"<")==0) cond=v1<v2;
            else if(strcmp(op_str,">")==0) cond=v1>v2;
            else if(strcmp(op_str,"==")==0) cond=v1==v2;
            else if(strcmp(op_str,"!=")==0) cond=v1!=v2;
            else if(strcmp(op_str,"<=")==0) cond=v1<=v2;
            else if(strcmp(op_str,">=")==0) cond=v1>=v2;
            if(cond) printf("%s\n",msg);
        }
        // ==================== simple assignment ====================
        else if(sscanf(line,"%s = %d",vname,&val)==2){
            setVarValue(name,var,count,vname,val);
        }
        // ==================== arithmetic assignment ====================
        else if(sscanf(line,"%s = %s %c %s",vname,a,&op,b)==4){
            int v1=getVarValue(name,var,count,a);
            int v2=getVarValue(name,var,count,b);
            int result=0;
            if(op=='+') result=v1+v2;
            else if(op=='-') result=v1-v2;
            else if(op=='*') result=v1*v2;
            else if(op=='/') result=(v2!=0)?v1/v2:0;
            setVarValue(name,var,count,vname,result);
        }
        // ==================== for-loop (যাবত) - FIXED VERSION ====================
        else if(strncmp(line,"যাবত",4)==0){
            char loopVar[50], startStr[50], condVar[50], cmp[3], endStr[50];
            sscanf(line,"যাবত %s = %s থেকে %s %s %s পর্যন্ত", 
                   loopVar, startStr, condVar, cmp, endStr);
            
            // Get start value
            int startVal;
            if(isdigit(startStr[0]) || (startStr[0] == '-' && isdigit(startStr[1]))) {
                startVal = atoi(startStr);
            } else {
                startVal = getVarValue(name,var,count,startStr);
            }
            
            // Get end value
            int endVal;
            if(isdigit(endStr[0]) || (endStr[0] == '-' && isdigit(endStr[1]))) {
                endVal = atoi(endStr);
            } else {
                endVal = getVarValue(name,var,count,endStr);
            }
            
            // Set initial loop variable value
            int loopIdx = getVarIndex(name,count,loopVar);
            if(loopIdx == -1){
                strcpy(name[count], loopVar);
                var[count] = startVal;
                loopIdx = count;
                count++;
            } else {
                var[loopIdx] = startVal;
            }
            
            // Find loop body boundaries
            int startLine = lineNum + 1;
            int endLine = totalLines;
            for(int l=lineNum+1; l<totalLines; l++){
                char tempLine[512];
                strcpy(tempLine, scriptLines[l]);
                trim(tempLine);
                if(strncmp(tempLine,"শেষ",4)==0){
                    endLine = l;
                    break;
                }
            }
            
            // Execute loop
            while(1){
                int loopVal = var[loopIdx];
                int conditionMet = 0;
                
                if(strcmp(cmp,"<")==0) conditionMet = loopVal < endVal;
                else if(strcmp(cmp,">")==0) conditionMet = loopVal > endVal;
                else if(strcmp(cmp,"<=")==0) conditionMet = loopVal <= endVal;
                else if(strcmp(cmp,">=")==0) conditionMet = loopVal >= endVal;
                else if(strcmp(cmp,"==")==0) conditionMet = loopVal == endVal;
                else if(strcmp(cmp,"!=")==0) conditionMet = loopVal != endVal;
                
                if(!conditionMet) break;
                
                // Execute loop body
                for(int ln=startLine; ln<endLine; ln++){
                    strcpy(line, scriptLines[ln]);
                    trim(line);
                    if(strlen(line) == 0) continue;
                    
                    // Handle all commands inside loop
                    if (sscanf(line, "নাও %s", vname) == 1) {
                        int temp;
                        printf("%s এর মান দিন: ", vname);
                        scanf("%d", &temp);
                        getchar();
                        setVarValue(name,var,count,vname,temp);
                    }
                    else if (sscanf(line, "সংখ্যা %s %d", vname, &val) == 2) {
                        int idx = getVarIndex(name, count, vname);
                        if (idx == -1) {
                            strcpy(name[count], vname);
                            var[count] = val;
                            count++;
                        } else {
                            var[idx] = val;
                        }
                    }
                    else if (sscanf(line, "সংখ্যা %s %s %c %s", vname, a, &op, b) == 4) {
                        int v1 = getVarValue(name,var,count,a);
                        int v2 = getVarValue(name,var,count,b);
                        int result=0;
                        if(op=='+') result=v1+v2;
                        else if(op=='-') result=v1-v2;
                        else if(op=='*') result=v1*v2;
                        else if(op=='/') result=(v2!=0)?v1/v2:0;
                        
                        int idx = getVarIndex(name, count, vname);
                        if (idx == -1) {
                            strcpy(name[count], vname);
                            var[count] = result;
                            count++;
                        } else {
                            var[idx] = result;
                        }
                    }
                    else if (strncmp(line,"লিখ",4)==0){
                        char *p=line+4;
                        while(*p){
                            while(isspace(*p)) p++;
                            if(*p=='"'){
                                char msg[200];
                                p++; int i=0;
                                while(*p && *p!='"') msg[i++]=*p++;
                                msg[i]=0;
                                if(*p=='"') p++;
                                printf("%s",msg);
                            }
                            else if(isalpha(*p)){
                                char varname[50]; int i=0;
                                while(*p && !isspace(*p) && *p!='"') varname[i++]=*p++;
                                varname[i]=0;
                                int idx=getVarIndex(name,count,varname);
                                if(idx!=-1) printf("%d",var[idx]);
                                else printf("%s",varname);
                            }
                            else p++;
                        }
                        printf("\n");
                    }
                    else if(sscanf(line,"%s = %s %c %s",vname,a,&op,b)==4){
                        int v1=getVarValue(name,var,count,a);
                        int v2=getVarValue(name,var,count,b);
                        int result=0;
                        if(op=='+') result=v1+v2;
                        else if(op=='-') result=v1-v2;
                        else if(op=='*') result=v1*v2;
                        else if(op=='/') result=(v2!=0)?v1/v2:0;
                        setVarValue(name,var,count,vname,result);
                    }
                    else if(sscanf(line,"%s = %d",vname,&val)==2){
                        setVarValue(name,var,count,vname,val);
                    }
                }
                
                // Increment loop variable
                var[loopIdx] = var[loopIdx] + 1;
            }
            
            lineNum = endLine;
        }
        // ==================== while-loop (যখন) ====================
        else if(strncmp(line,"যখন",4)==0){
            char condVar[50], cmp[3], endStr[50];
            
            // Parse: যখন i <= 5
            char *ptr = line + 4;
            while(*ptr && isspace(*ptr)) ptr++;
            
            sscanf(ptr, "%s %s %s", condVar, cmp, endStr);
            
            int endVal;
            if(isdigit(endStr[0]) || (endStr[0] == '-' && isdigit(endStr[1]))) {
                endVal = atoi(endStr);
            } else {
                endVal = getVarValue(name,var,count,endStr);
            }
            
            int startLine = lineNum + 1;
            int endLine = totalLines;
            
            for(int l=lineNum+1; l<totalLines; l++){
                char tempLine[512];
                strcpy(tempLine, scriptLines[l]);
                trim(tempLine);
                if(strncmp(tempLine,"শেষ",4)==0){
                    endLine = l;
                    break;
                }
            }
            
            // While loop execution
            while(1){
                int varVal = getVarValue(name, var, count, condVar);
                int condMet = 0;
                
                if(strcmp(cmp,"<")==0) condMet = varVal < endVal;
                else if(strcmp(cmp,">")==0) condMet = varVal > endVal;
                else if(strcmp(cmp,"<=")==0) condMet = varVal <= endVal;
                else if(strcmp(cmp,">=")==0) condMet = varVal >= endVal;
                else if(strcmp(cmp,"==")==0) condMet = varVal == endVal;
                else if(strcmp(cmp,"!=")==0) condMet = varVal != endVal;
                
                if(!condMet) break;
                
                // Execute loop body
                for(int ln=startLine; ln<endLine; ln++){
                    strcpy(line, scriptLines[ln]);
                    trim(line);
                    if(strlen(line) == 0) continue;
                    
                    if (sscanf(line, "নাও %s", vname) == 1) {
                        int temp;
                        printf("%s এর মান দিন: ", vname);
                        scanf("%d", &temp);
                        getchar();
                        setVarValue(name,var,count,vname,temp);
                    }
                    else if (sscanf(line, "সংখ্যা %s %d", vname, &val) == 2) {
                        int idx = getVarIndex(name, count, vname);
                        if (idx == -1) {
                            strcpy(name[count], vname);
                            var[count] = val;
                            count++;
                        } else {
                            var[idx] = val;
                        }
                    }
                    else if (sscanf(line, "সংখ্যা %s %s %c %s", vname, a, &op, b) == 4) {
                        int v1 = getVarValue(name,var,count,a);
                        int v2 = getVarValue(name,var,count,b);
                        int result=0;
                        if(op=='+') result=v1+v2;
                        else if(op=='-') result=v1-v2;
                        else if(op=='*') result=v1*v2;
                        else if(op=='/') result=(v2!=0)?v1/v2:0;
                        
                        int idx = getVarIndex(name, count, vname);
                        if (idx == -1) {
                            strcpy(name[count], vname);
                            var[count] = result;
                            count++;
                        } else {
                            var[idx] = result;
                        }
                    }
                    else if (strncmp(line,"লিখ",4)==0){
                        char *p=line+4;
                        while(*p){
                            while(isspace(*p)) p++;
                            if(*p=='"'){
                                char msg[200];
                                p++; int i=0;
                                while(*p && *p!='"') msg[i++]=*p++;
                                msg[i]=0;
                                if(*p=='"') p++;
                                printf("%s",msg);
                            }
                            else if(isalpha(*p)){
                                char varname[50]; int i=0;
                                while(*p && !isspace(*p) && *p!='"') varname[i++]=*p++;
                                varname[i]=0;
                                int idx=getVarIndex(name,count,varname);
                                if(idx!=-1) printf("%d",var[idx]);
                                else printf("%s",varname);
                            }
                            else p++;
                        }
                        printf("\n");
                    }
                    else if(sscanf(line,"%s = %s %c %s",vname,a,&op,b)==4){
                        int v1=getVarValue(name,var,count,a);
                        int v2=getVarValue(name,var,count,b);
                        int result=0;
                        if(op=='+') result=v1+v2;
                        else if(op=='-') result=v1-v2;
                        else if(op=='*') result=v1*v2;
                        else if(op=='/') result=(v2!=0)?v1/v2:0;
                        setVarValue(name,var,count,vname,result);
                    }
                    else if(sscanf(line,"%s = %d",vname,&val)==2){
                        setVarValue(name,var,count,vname,val);
                    }
                }
            }
            lineNum = endLine;
        }
        // ==================== সংখ্যা declaration without value ====================
        else if (sscanf(line, "সংখ্যা %s", vname) == 1) {
            int idx = getVarIndex(name, count, vname);
            if (idx == -1) {
                strcpy(name[count], vname);
                var[count] = 0;
                count++;
            }
        }
    }

    color("\033[1;32m");
    printf("\nScript finished successfully.\n");
    color("\033[0m");
}

// ===================== MENU FUNCTIONS =====================
void help(){
    clearScreen();
    banner();
    color("\033[1;33m");
    printf("Bangla Script Syntax Help:\n\n");
    color("\033[0m");
    printf("1) Variable: সংখ্যা x 5\n");
    printf("2) Print: লিখ \"Hello\" or লিখ x or লিখ \"a = \" লিখ a\n");
    printf("3) If condition: যদি a < b লিখ \"a small\"\n");
    printf("4) Assignment: a = 10\n");
    printf("5) Arithmetic: a = b + c , a = b - c , a = b * c , a = b / c\n");
    printf("6) For loop: যাবত i = 0 থেকে i < 10 পর্যন্ত ... শেষ\n");
    printf("7) While loop: যখন a < 5 ... শেষ\n");
    printf("8) Input: নাও x\n\n");
    printf("Press ENTER to return...");
    getchar();
}

void open_editor(){
    clearScreen();
    banner();
    printf("Opening script editor...\n");
#ifdef _WIN32
    system("notepad.exe");
#else
    system("nano");
#endif
    printf("\nPress ENTER to continue...");
    getchar();
}

void menu(){
    clearScreen();
    banner();
    color("\033[1;36m");
    printf("1. Run Script File\n");
    printf("2. Open Script Editor\n");
    printf("3. Help\n");
    printf("4. Exit\n");
    color("\033[0m");
    printf("\nChoose option: ");
}

// ===================== LANGUAGE SELECTION =====================
int language_selection(){
    int lang;
    clearScreen();
    banner();
    printf("Select Language:\n");
    printf("1. Bangla\n");
    printf("2. C (Coming Soon)\n");
    printf("3. C++ (Coming Soon)\n");
    printf("\nEnter choice: ");
    scanf("%d",&lang);
    getchar();
    return lang;
}

// ==================== MAIN =====================
int main()
{
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(CP_UTF8);
#endif
    setlocale(LC_ALL, "bn_BD.utf8");

    int lang=language_selection();

    if(lang==1){
        int choice;
        char file[200];
        while(1){
            menu();
            scanf("%d",&choice);
            getchar();
            switch(choice){
                case 1:
                    printf("Enter script filename: ");
                    fgets(file,sizeof(file),stdin);
                    file[strcspn(file,"\n")]=0;
                    run_script(file);
                    printf("\nPress ENTER to continue...");
                    getchar();
                    break;
                case 2:
                    open_editor();
                    break;
                case 3:
                    help();
                    break;
                case 4:
                    clearScreen();
                    printf("Goodbye!\n");
                    return 0;
                default:
                    printf("Invalid option!\n");
            }
        }
    }
    else if(lang==2){
        clearScreen();
        printf("C language IDE not implemented yet!\n");
    }
    else if(lang==3){
        clearScreen();
        printf("C++ language IDE not implemented yet!\n");
    }
    else{
        clearScreen();
        printf("Invalid language selection!\n");
    }

    return 0;
}
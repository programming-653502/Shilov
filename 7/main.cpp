//
//  Created by Максим Шилов on 18.02.17.
//  Copyright © 2017 Максим Шилов. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Crime;
struct Criminal;

typedef struct Crime{
    char* place;
    Criminal* participants = (Criminal*) malloc(sizeof(Criminal*) * 100);
    char* effects;
    char* comments;
} Crime;

typedef struct Organisation{
    char* name;
    char* kindOfActivity;
    int rating;
} Organisation;

typedef struct Criminal{
    char* name;
    char* nickname;
    int height;
    int weight;
    char* hairColor;
    char* specialSigns;
    char* citizenship;
    char* kindOfCrime;
    char* languages;
    Organisation* organisations;
    int organisationCount;
    Crime* crimeList;
    int crimeCount;
} Criminal;

Organisation organisationInitializer(char* name, char* kindOfActivity, int rating){
    Organisation organisation;
    organisation.name = name;
    organisation.kindOfActivity = kindOfActivity;
    organisation.rating = rating;
    return organisation;
}

Criminal criminalInitializer(char* name, char* nickname, int height, int weight, char* haircolor, char* specialSigns, char* citizenship, char* kindOfCrime, char* languages, Organisation* organisations, int organisationCount, Crime* crimeList, int crimeCount){
    Criminal criminal;
    criminal.name = name;
    criminal.nickname = nickname;
    criminal.height = height;
    criminal.weight = weight;
    criminal.hairColor = haircolor;
    criminal.specialSigns = specialSigns;
    criminal.citizenship = citizenship;
    criminal.kindOfCrime = kindOfCrime;
    criminal.languages = languages;
    criminal.organisations = organisations;
    criminal.organisationCount = organisationCount;
    criminal.crimeList = crimeList;
    criminal.crimeCount = crimeCount;
    return criminal;
}

Crime crimeInitializer(char* place, char* effects, char* comments){
    Crime crime;
    crime.place = place;
    crime.effects = effects;
    crime.comments = comments;
    return crime;
}

Crime addCrime(){
    Crime crime;
    char* place = (char*)malloc(sizeof(char*)*100);
    char* effects = (char*)malloc(sizeof(char*)*100);
    char* comments = (char*)malloc(sizeof(char*)*100);
    rewind(stdin);
    puts("Введите место преступления:");
    scanf("%[^\n]s", place);
    rewind(stdin);
    puts("Введите последствия преступления:");
    scanf("%[^\n]s", effects);
    rewind(stdin);
    puts("Введите комментарии к преступлению:");
    scanf("%[^\n]s", comments);
    rewind(stdin);
    crime = crimeInitializer(place, effects, comments);
//    free(place);
//    free(effects);
//    free(comments);
    return crime;
}

void showCrime(Crime crime){
    printf("Место преступления: %s\nПоследствия преступления: %s\nКомментарии к преступлению: %s\n", crime.place, crime.effects, crime.comments);
}

void showAllCrimes(int countOfCrimes, Crime *crimes){
    for(int i = 0; i < countOfCrimes; i++){
        showCrime(crimes[i]);
    }
}

Organisation addOrganisation(){
    rewind(stdin);
    Organisation organisation;
    int rating;
    char *name, *kindOfActivity;
    puts("Введите название организации");
    name = (char*)malloc(sizeof(char)* 100);
    scanf("%[^\n]s", name);
    rewind(stdin);
    kindOfActivity = (char*)malloc(sizeof(char)* 100);
    puts("Введите вид деятельности организации");
    scanf("%[^\n]s", kindOfActivity);
    puts("Укажите рейтинг опасности организации (от 1 до 10)");
    scanf("%d", &rating);
    while(rating < 1 || rating > 10){
        rewind(stdin);
        puts("Укажите рейтинг опасности организации (от 1 до 10)");
        scanf("%d", &rating);
    }
    organisation = organisationInitializer(name, kindOfActivity, rating);
    return organisation;
}

Criminal addCriminal(Organisation* organisations, int count){
    char *name = (char*)malloc(sizeof(char*)* 100);
    char *nickname = (char*)malloc(sizeof(char*) * 100);
    char *haircolor = (char*)malloc(sizeof(char*) * 100);
    char *specialSigns = (char*)malloc(sizeof(char*) * 100);
    char *citizenship = (char*)malloc(sizeof(char*) * 100);
    char *languages = (char*)malloc(sizeof(char*)* 100);
    Crime* crimelist;
    Organisation* orgs;
    char *kindOfCrime = (char*)malloc(sizeof(char*) * 100);
    int height, weight;
    rewind(stdin);
    puts("Введите ФИО преступника:");
    scanf("%[^\n]s", name);
    rewind(stdin);
    puts("Введите кличку преступника:");
    scanf("%[^\n]s", nickname);
    rewind(stdin);
    puts("Введите рост преступника:");
    scanf("%d", &height);
    while(height < 20 || height > 300){
        rewind(stdin);
        puts("Введите корректный рост преступника: ");
        scanf("%d", &height);
    }
    puts("Введите вес преступника:");
    scanf("%d", &weight);
    while(weight < 20 || weight > 400){
        rewind(stdin);
        puts("Введите корректный вес преступника: ");
        scanf("%d", &weight);
    }
    rewind(stdin);
    puts("Введите цвет волос преступника:");
    scanf("%[^\n]s", haircolor);
    rewind(stdin);
    puts("Введите особые приметы преступника:");
    scanf("%[^\n]s", specialSigns);
    rewind(stdin);
    puts("Введите гражданство преступника:");
    scanf("%[^\n]s", citizenship);
    rewind(stdin);
    puts("Какие языки знает преступник?");
    scanf("%[^\n]s", languages);
    rewind(stdin);
    puts("Введите род преступления преступника:");
    scanf("%[^\n]s", kindOfCrime);
    rewind(stdin);
    int orgCount;
    puts("В скольких террористических организациях состоит?");
    scanf("%d", &orgCount);
    while(orgCount < 1 || orgCount > 10){
        rewind(stdin);
        puts("Число организаций, в которых состоит преступник должно быть > 0. В скольких террористических организациях преступник состоит?");
        scanf("%d", &orgCount);
    }
    rewind(stdin);
    puts("Укажите номера организациий, в которых состоит преступник: ");
    orgs = (Organisation*)malloc(sizeof(Organisation*) * orgCount);
    rewind(stdin);
    for (int i = 0; i < orgCount; i++){
        puts("Введите номер организации: \n");
        for (int j = 0; j < count; j++){
            if(i == 0 || strcmp(organisations[j].name, orgs[i - 1].name) != 0)
                printf("%d. %s\n", j + 1, organisations[j].name);
        }
        int choise = 1;
        scanf("%d", &choise);
        while(choise < 1 || choise > orgCount){
            rewind(stdin);
            puts("Введите корректный номер организации: ");
            scanf("%d", &choise);
        }
        orgs[i] = organisations[choise - 1];
    }
    int crimeCount;
    puts("Сколько преступлений совершил преступник?");
    scanf("%d", &crimeCount);
    while(crimeCount < 1 || crimeCount > 10){
        rewind(stdin);
        puts("Число преступлений должно быть > 0. Сколько преступлений совершил преступник?");
        scanf("%d", &crimeCount);
    }
    crimelist = (Crime*) calloc(crimeCount, sizeof(Crime*));
    for (int i = 0; i < crimeCount; i++){
        crimelist[i] = addCrime();
    }
    Criminal criminal = criminalInitializer(name, nickname, height, weight, haircolor, specialSigns, citizenship, kindOfCrime, languages, orgs, orgCount, crimelist, crimeCount);
    return criminal;
    
}

void showCriminal(Criminal criminal){
    printf("\
ФИО преступника - %s\n\
Кличка - %s\n\
Рост - %d\n\
Вес - %d\n\
Цвет волос - %s\n\
Особые приметы - %s\n\
Гражданство - %s\n\
Знание языков - %s\n\
Род преступления - %s\n\
Состоит в %d организации(ях): ", criminal.name, criminal.nickname, criminal.height, criminal.weight,
           criminal.hairColor, criminal.specialSigns, criminal.citizenship, criminal.languages, criminal.kindOfCrime, criminal.organisationCount);
    for (int i = 0; i < criminal.organisationCount; i++){
        printf("%s", criminal.organisations[i].name);
        if(i != criminal.organisationCount - 1)
            printf(", ");
        else
            printf(".\n");
    }
    printf("Преступления: \n");
    for (int i = 0; i < criminal.crimeCount; i++){
        showCrime(criminal.crimeList[i]);
        if(i != criminal.crimeCount - 1)
            printf("*********************************\n");
        else
            printf("\n");
    }
}

void showAllCriminals(int criminalsCount, Criminal* criminals){
    for (int i = 0; i < criminalsCount; i++){
        printf("----------------------------------\n");
        printf("%d-й преступник:\n", i + 1);
        printf("----------------------------------\n");
        showCriminal(criminals[i]);
    }
}

void showAllCrimes(int criminalsCount, Criminal* criminals){
    for (int i = 0; i < criminalsCount; i++){
        for (int j = 0; j < criminals[i].crimeCount; j++)
            showCrime(criminals[i].crimeList[j]);
    }
}

void showOrganisation(Organisation org){
    puts("------------------------------");
    printf("Название организации - %s\nВид деятельности - %s\nРейтинг опасности - %d\n", org.name, org.kindOfActivity, org.rating);
    puts("------------------------------");
}

void showAllOrganisations(int orgCount, Organisation* organisations){
    for (int i = 0; i < orgCount; i++){
        showOrganisation(organisations[i]);
    }
}

Organisation findOrganisationByName(char* name, Organisation* organisations, int count){
    for (int i = 0; i < count; i++){
        printf("%d", strcmp(organisations[i].name, name));
        if(strcmp(organisations[i].name, name) == 0){
            return organisations[i];
        }
    }
    Organisation o;
    return o;
}

Crime addTempCrime(){
    Crime crime;
    char* place = (char*)"ТЦ \"Европа\"";
    char* effects = (char*)"Погиб человек, 2 пострадали";
    char* comments = (char*)"Нет комментариев";
    crime = crimeInitializer(place, effects, comments);
    return crime;
}

Criminal addStandartCriminal(Organisation* organisations, int count, char* name, char* nickname, char* haircolor, char* specialSigns, char* citizenship, char* languages, char* kindOfCrime, int height, int weight){
    Crime* crimelist;
    Organisation* orgs;
    int orgCount = 1;
    orgs = (Organisation*)calloc(orgCount + 1, sizeof(Organisation));
    for (int i = 0; i < orgCount; i++){
        int choise = 1;
        orgs[i] = organisations[choise - 1];
    }
    int crimeCount;
    puts("Сколько преступлений совершил преступник?");
    scanf("%d", &crimeCount);
    crimelist = (Crime*) calloc(crimeCount, sizeof(Crime*));
    for (int i = 0; i < crimeCount; i++){
        crimelist[i] = addTempCrime();
    }
    Criminal criminal = criminalInitializer(name, nickname, height, weight, haircolor, specialSigns, citizenship, kindOfCrime, languages, orgs, orgCount, crimelist, crimeCount);
    free(orgs);
    free(crimelist);
    return criminal;
}


int menu(){
    int n;
    puts("------------------------------");
    printf("1. Показать всех преступников\n2. Показать все преступления\n3. Показать все преступные организации\n4. Поиск\n5. Редактирование\n9. Выход\n");
    scanf("%d", &n);
    rewind(stdin);
    return n;
}

int searchMenu(){
    int n;
    printf("1. Поиск по преступникам\n2. Поиск по преступлениям\n3. Поиск по преступным организациям\n");
    scanf("%d", &n);
    return n;
}

void searchByCriminals(int countOfCriminals, Criminal* criminals){
    char* s = (char*) malloc(sizeof(char) * 100);
    printf("Введите ключевое слово для поиска:\n");
    scanf("%s", s);
    printf("Результаты поиска: \n");
    int count = 0;
    for(int i = 0; i < countOfCriminals; i++){
        if((!strcmp(s, criminals[i].name) || !strcmp(s, criminals[i].nickname) || !strcmp(s, criminals[i].hairColor)
            || !strcmp(s, criminals[i].specialSigns) || !strcmp(s, criminals[i].citizenship) || !strcmp(s, criminals[i].kindOfCrime)
            || !strcmp(s, criminals[i].languages))){
            showCriminal(criminals[i]);
            count++;
        }
    }
    if(count == 0){
        printf("По запросу \"%s\" ничего не найдено.\n", s);
    }
    free(s);
}

void searchByCrimes(int countOfCriminals, Criminal* criminals){
    char* s = (char*) malloc(sizeof(char) * 100);
    printf("Введите ключевое слово для поиска:\n");
    scanf("%s", s);
    printf("Результаты поиска: \n");
    int count = 0;
    for(int i = 0; i < countOfCriminals; i++){
        for(int j = 0; j < criminals[i].crimeCount; j++){
            if(!strcmp(s, criminals[i].crimeList[j].comments) || !strcmp(s, criminals[i].crimeList[j].effects) || !strcmp(s, criminals[i].crimeList[j].place)){
                showCrime(criminals[i].crimeList[j]);
                count++;
            }
        }
    }
    if(count == 0){
        printf("По запросу \"%s\" ничего не найдено.\n", s);
    }
    free(s);
}

void searchByOrganisation(int countOfOrganisations, Organisation* organisations){
    char* s = (char*) malloc(sizeof(char) * 100);
    printf("Введите ключевое слово для поиска:\n");
    scanf("%s", s);
    printf("Результаты поиска: \n");
    int count = 0;
    for(int i = 0; i < countOfOrganisations; i++){
        if(!strcmp(s, organisations[i].name) || !strcmp(s, organisations[i].kindOfActivity)){
            showOrganisation(organisations[i]);
            count++;
        }
    }
    if(count == 0){
        printf("По запросу \"%s\" ничего не найдено.\n", s);
    }
    free(s);
}

void search(int countOfCriminals, Criminal* criminals, int countOfOrganisations, Organisation* organisations){
    switch (searchMenu()) {
        case 1:
            searchByCriminals(countOfCriminals, criminals);
            break;
        case 2:
            searchByCrimes(countOfCriminals, criminals);
            break;
        case 3:
            searchByOrganisation(countOfOrganisations, organisations);
            break;
        default:
            break;
    }
}

int editMenu(){
    int n;
    printf("1. Добавить преступника\n2. Добавить преступление\n3. Добавить преступную организацию\n4. Изменить данные о преступнике\n5. Изменить данные о преступлении\n6. Изменить данные о преступной организации\n7. Удалить умершего преступника\n");
    scanf("%d", &n);
    return n;
}

void addCriminalToCriminalList(int countOfOrganisations, Organisation* organisations, int *countOfCriminals, Criminal* criminals){
    Criminal criminal = addCriminal(organisations, countOfOrganisations);
    Criminal* newCriminals = (Criminal*) realloc(criminals, (*countOfCriminals + 1) * sizeof(Criminal));
    ++*countOfCriminals;
    newCriminals[*countOfCriminals - 1] = criminal;
    criminals = newCriminals;
    puts("Преступник был добавлен!");
    //    free(newCriminals);
}

void showCriminalAsList(int countOfCriminals, Criminal* criminals){
    printf("----------------------------------\n");
    for (int i = 0; i < countOfCriminals; i++){
        printf("%d. %s\n", i + 1, criminals[i].name);
    }
    printf("----------------------------------\n");
}

void addCrimeToCrimeList(int countOfCriminals, Criminal* criminals){
    printf("Укажите номер преступника, совершившего преступление: \n");
    int n;
    showCriminalAsList(countOfCriminals, criminals);
    scanf("%d", &n);
    while(n < 1 || n > countOfCriminals){
        rewind(stdin);
        printf("Укажите корректный номер преступника, совершившего преступление: \n");
        showCriminalAsList(countOfCriminals, criminals);
        scanf("%d", &n);
    }
    int count = criminals[n - 1].crimeCount + 1;
    Crime *crimeList = (Crime*) calloc(count, sizeof(Crime));
    criminals[n - 1].crimeCount = count;
    for(int i = 0; i < count - 1; i++){
        crimeList[i] = criminals[n - 1].crimeList[i];
    }
    crimeList[count - 1] = addCrime();
    criminals[n - 1].crimeList = crimeList;
    showAllCrimes(count, criminals[n - 1].crimeList);
}

void addOrganisationsToOrganisationsList(int *countOfOrganisations, Organisation* organisations){
    Organisation* temp = (Organisation*) calloc(*countOfOrganisations + 1, sizeof(Organisation));
    for (int i = 0; i < *countOfOrganisations; i++){
        temp[i] = organisations[i];
    }
//    Organisation* temp = (Organisation*) realloc(organisations, (*countOfOrganisations + 1) * sizeof(Organisation));
    temp[*countOfOrganisations] = addOrganisation();
    ++*countOfOrganisations;
    organisations = temp;
    printf("Организация \"%s\" была добавлена\n", organisations[*countOfOrganisations - 1].name);
}

Criminal changeCriminal(Criminal criminal, int *countOfOrganisations, Organisation* organisations){
    printf("Укажите, что вы хотите изменить:\n1.ФИО\n2.Кличка\n3.Рост\n4.Вес\n5.Цвет волос\n6.Особые приметы\n7.Гражданство\n8.Знание языков\n9.Участие в преступной организации\n");
    int n, orgCount;
    Organisation* orgs;
    char* str;
    scanf("%d", &n);
    switch (n) {
        case 1:
            puts("Введите новое ФИО:");
            scanf("%[^\n]s", str);
            rewind(stdin);
            criminal.name = str;
            break;
        case 2:
            puts("Введите новую кличку:");
            scanf("%[^\n]s", str);
            rewind(stdin);
            criminal.nickname = str;
            break;
        case 3:
            puts("Введите новый рост:");
            scanf("%d", &n);
            while(n < 20 || n > 300){
                rewind(stdin);
                puts("Введите корректный рост преступника: ");
                scanf("%d", &n);
            }
            criminal.height = n;
            break;
        case 4:
            puts("Введите новый вес:");
            scanf("%d", &n);
            while(n < 20 || n > 400){
                rewind(stdin);
                puts("Введите корректный вес преступника: ");
                scanf("%d", &n);
            }
            criminal.weight = n;
            break;
        case 5:
            puts("Введите новый цвет волос:");
            scanf("%[^\n]s", str);
            criminal.hairColor = str;
            break;
        case 6:
            puts("Введите особые приметы:");
            scanf("%[^\n]s", str);
            criminal.specialSigns = str;
            break;
            break;
        case 7:
            puts("Введите новое гражданство:");
            scanf("%[^\n]s", str);
            criminal.citizenship = str;
            break;
        case 8:
            puts("Какие языки знает преступник?");
            scanf("%[^\n]s", str);
            criminal.languages = str;
            break;
        case 9:
            puts("В скольких организациях состоит?");
            scanf("%d", &orgCount);
            while(orgCount < 1 || orgCount > 10){
                rewind(stdin);
                puts("Число организаций, в которых состоит преступник должно быть > 0. В скольких террористических организациях преступник состоит?");
                scanf("%d", &orgCount);
            }
            rewind(stdin);
            puts("Укажите номера организациий, в которых состоит преступник: ");
            orgs = (Organisation*)malloc(sizeof(Organisation*) * orgCount);
            rewind(stdin);
            for (int i = 0; i < orgCount; i++){
                puts("Введите номер организации: \n");
                for (int j = 0; j < *countOfOrganisations; j++){
                    if(i == 0 || strcmp(organisations[j].name, orgs[i - 1].name) != 0)
                        printf("%d. %s\n", j + 1, organisations[j].name);
                }
                int choise = 1;
                scanf("%d", &choise);
                while(choise < 1 || choise > orgCount){
                    rewind(stdin);
                    puts("Введите корректный номер организации: ");
                    scanf("%d", &choise);
                }
                orgs[i] = organisations[choise - 1];
            }
            criminal.organisations = orgs;
            break;
        default:
            break;
    }
    return criminal;
}

Crime changeCrime(Crime crime){
    printf("Укажите, что вы хотите изменить:\n1.Место преступления\n2.Последствия преступления\n3.Комментарии к преступлению\n");
    int n;
    char* str;
    scanf("%d", &n);
    while(n < 1 || n > 10){
        rewind(stdin);
        printf("Укажите, что вы хотите изменить:\n1.Место преступления\n2.Последствия преступления\n3.Комментарии к преступлению\n");
        scanf("%d", &n);
    }
    switch(n) {
        case 1:
            puts("Введите место преступлени:");
            scanf("%[^\n]s", str);
            rewind(stdin);
            crime.place = str;
            break;
        case 2:
            puts("Введите последствия преступления:");
            scanf("%[^\n]s", str);
            rewind(stdin);
            crime.effects = str;
            break;
        case 3:
            puts("Введите комментарии к преступлению:");
            scanf("%[^\n]s", str);
            rewind(stdin);
            crime.comments = str;
            break;
        default:
            break;
    }
    return crime;
}

Organisation changeOrganisation(Organisation organisation){
    printf("Укажите, что вы хотите изменить:\n1.Название организации\n2.Вид деятельности\n3.Рейтинг опасности\n");
    int n;
    char* str = (char*) calloc(100, sizeof(char));
    scanf("%d", &n);
    while(n < 1 || n > 10){
        rewind(stdin);
        printf("Укажите, что вы хотите изменить:\n1.Название организации\n2.Вид деятельности\n3.Рейтинг опасности\n");
        scanf("%d", &n);
    }
    switch(n) {
        case 1:
            puts("Введите название организации:");
            scanf("%[^\n]s", str);
            organisation.name = str;
            break;
        case 2:
            puts("Введите вид деятельности:");
            scanf("%[^\n]s", str);
            organisation.kindOfActivity = str;
            break;
        case 3:
            puts("Введите рейтинг опасности (от 1 до 10):");
            scanf("%d", &n);
            while(n < 1 || n > 10){
                rewind(stdin);
                puts("Введите рейтинг опасности (от 1 до 10):");
                scanf("%d", &n);
            }
            organisation.rating = n;
            break;
        default:
            break;
    }
    return organisation;
}

Criminal* deleteCriminal(Criminal* criminals, int *countOfCriminals, int n){
    Criminal* newCriminals = (Criminal*)calloc(*countOfCriminals - 1, sizeof(Criminal));
    int j = 0;
    for (int i = 0; i < *countOfCriminals; i++){
        if(i != n){
            newCriminals[j] = criminals[i];
            j++;
        }
    }
    --*countOfCriminals;
    return newCriminals;
    
}

void edit(int *countOfCriminals, Criminal* criminals, int *countOfOrganisations, Organisation* organisations){
    int n, count;
    switch (editMenu()) {
        case 1:
            addCriminalToCriminalList(*countOfOrganisations, organisations, countOfCriminals, criminals);
            break;
        case 2:
            addCrimeToCrimeList(*countOfCriminals, criminals);
            break;
        case 3:
            addOrganisationsToOrganisationsList(countOfOrganisations, organisations);
            break;
        case 4:
            puts("Укажите номер редактируемого преступника");
            showCriminalAsList(*countOfCriminals, criminals);
            scanf("%d", &n);
            while(n < 1 || n > *countOfCriminals){
                rewind(stdin);
                puts("Укажите корректный номер редактируемого преступника");
                showCriminalAsList(*countOfCriminals, criminals);
                scanf("%d", &n);
            }
            criminals[n - 1] = changeCriminal(criminals[n - 1], countOfOrganisations, organisations);
            break;
        case 5:
            puts("Укажите номер редактируемого преступления");
            count = 0;
            for (int i = 0; i < *countOfCriminals; i++){
                for (int j = 0; j < criminals[i].crimeCount; j++){
                    count++;
                    printf("----------------------------------\n%d-е преступление:\n----------------------------------\n", count);
                    showCrime(criminals[i].crimeList[j]);
                }
            }
            scanf("%d", &n);
            count = 0;
            for (int i = 0; i < *countOfCriminals; i++){
                for (int j = 0; j < criminals[i].crimeCount; j++){
                    count++;
                    if(count == n){
                        criminals[i].crimeList[j] = changeCrime(criminals[i].crimeList[j]);
                        break;
                    }
                }
            }
            break;
        case 6:
            puts("Укажите номер преступной организации:");
            for(int i = 0; i < *countOfOrganisations; i++){
                printf("%d.%s\n", i + 1, organisations[i].name);
            }
            scanf("%d", &n);
            while(n < 1 || n > *countOfOrganisations){
                rewind(stdin);
                puts("Укажите корректный номер преступной организации:");
                scanf("%d", &n);
            }
            organisations[n - 1] = changeOrganisation(organisations[n - 1]);
            break;
        case 7:
            puts("Укажите номер умершего преступника");
            showCriminalAsList(*countOfCriminals, criminals);
            scanf("%d", &n);
            criminals = deleteCriminal(criminals, countOfCriminals, n);
        default:
            break;
    }
}


int main(void) {
    int countOfOrganisations, countOfCriminals;
    Organisation* organisations;
    Criminal* criminals;
    puts("Сколько организаций вы хотите ввести?");
    
    scanf("%d", &countOfOrganisations);
    while(countOfOrganisations < 1 || countOfOrganisations > 10){
        rewind(stdin);
        puts("Сколько организаций вы хотите ввести?");
        scanf("%d", &countOfOrganisations);
    }
    organisations = (Organisation*) malloc(sizeof(Organisation*) * countOfOrganisations);
    for (int i = 0; i < countOfOrganisations; i++){
        organisations[i] = addOrganisation();
    }
    for (int i = 0; i < countOfOrganisations; i++)
        showOrganisation(organisations[i]);
    puts("Сколько преступников вы хотите ввести?");
    scanf("%d", &countOfCriminals);
    while(countOfCriminals < 1 || countOfCriminals > 10){
        rewind(stdin);
        puts("Сколько преступников вы хотите ввести?");
        scanf("%d", &countOfCriminals);
    }
    criminals = (Criminal*) malloc(sizeof(Criminal*) * countOfCriminals);
    for(int i = 0; i < countOfCriminals; i++){
        criminals[i] = addCriminal(organisations, countOfOrganisations);
    }
    
//    countOfOrganisations = 2;
//    organisations = (Organisation*) calloc(countOfOrganisations, sizeof(Organisation));
//    organisations[0] = organisationInitializer("ИГИЛ", "Убийства", 9);
//    organisations[1] = organisationInitializer("БРСМ", "Изнасилование", 10);
//    for (int i = 0; i < countOfOrganisations; i++)
//        showOrganisation(organisations[i]);
//    countOfCriminals = 2;
//    criminals = (Criminal*) calloc(countOfCriminals, sizeof(Criminal));
//    for (int i = 0; i < countOfCriminals; i++){
//        criminals[i] = addStandartCriminal(organisations, countOfOrganisations, "Шпаков Никита Игоревич", "Никитка", "Чёрный", "Татуха", "белорус", "Русский, белорусский, английский", "убийство", 180, 80);
//        for (int j = 0; j < criminals[i].crimeCount; j++){
//            criminals[i].crimeList[j].participants[0] = criminals[i];
//        }
//    }
    for (int i = 0; i < countOfCriminals; i++){
        showCriminal(criminals[i]);
        if(i + 1 != countOfCriminals)
            puts("------------------------------");
    }
    while(true){
        switch (menu()) {
            case 1:
                showAllCriminals(countOfCriminals, criminals);
                break;
            case 2:
                showAllCrimes(countOfCriminals, criminals);
                break;
            case 3:
                showAllOrganisations(countOfOrganisations, organisations);
                break;
            case 4:
                search(countOfCriminals, criminals, countOfOrganisations, organisations);
                break;
            case 5:
                edit(&countOfCriminals, criminals, &countOfOrganisations, organisations);
                break;
            case 9:
                exit(0);
                break;
            default:
                break;
        }
    }
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[10];
    char name[50];
    float basicSalary;
    float positionSalary;
    float allowance;
    float medicalInsurance;
    float providentFund;
    float totalSalary;
} Employee;

void inputRecord(Employee* employee, int* count);
void displayRecord(const Employee* employee, int count);
void modifyRecord(Employee* employee, int count);
void searchRecord(Employee* employee, int count);
void deleteRecord(Employee* employee, int* count);
void statistics(Employee* employee, int count);
void saveData(Employee* employee, int count);

int main() {

    Employee* employee = NULL;

    FILE* file = fopen("employee_data.txt", "rb");
    if (file == NULL) {
        perror("文件打开失败");
    }
    employee = (Employee*)calloc(1, sizeof(Employee));
    int count = 0;
    while (fread(&employee[count], sizeof(Employee), 1, file))
    {
        count++;
        employee = (Employee*)realloc(employee, (count + 1) * sizeof(Employee));
    }
    fclose(file);



    int choice;
    do {
        printf("\n===== 职工工资管理系统 =====\n");
        printf("1. 输入记录\n");
        printf("2. 显示记录\n");
        printf("3. 修改记录\n");
        printf("4. 查找记录\n");
        printf("5. 删除记录\n");
        printf("6. 统计\n");
        printf("7. 保存数据\n");
        printf("0. 退出\n");
        printf("请输入选择：");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            inputRecord(employee, &count);
            break;
        case 2:
            displayRecord(employee, count);
            break;
        case 3:
            modifyRecord(employee, count);
            break;
        case 4:
            searchRecord(employee, count);
            break;
        case 5:
            deleteRecord(employee, &count);
            break;
        case 6:
            statistics(employee, count);
            break;
        case 7:
            saveData(employee, count);
            break;
        case 0:
            printf("退出程序。\n");
            break;
        default:
            printf("无效的选择，请重新输入。\n");
        }
    } while (choice != 0);


    return 0;
}

void inputRecord(Employee* employee, int* count) {



    //if (employee == NULL) {
    printf("请输入职工ID号：");
    employee = (Employee*)realloc(employee, (*count + 1) * sizeof(Employee));
    scanf("%9s", employee[*count].id);

    //// 读取已存在的记录
    //if (fread(&newEmployee, sizeof(Employee), 1, file) == 1) {
    //    printf("请输入职工姓名：");
    //    scanf("%49s", newEmployee.name);

    //    printf("请输入基本工资：");
    //    scanf("%f", &newEmployee.basicSalary);

    //    printf("请输入职务工资：");
    //    scanf("%f", &newEmployee.positionSalary);

    //    printf("请输入岗位津贴：");
    //    scanf("%f", &newEmployee.allowance);

    //    printf("请输入医疗保险：");
    //    scanf("%f", &newEmployee.medicalInsurance);

    //    printf("请输入公积金：");
    //    scanf("%f", &newEmployee.providentFund);
    //}
    //else {
        // 如果没有已存在的记录，则继续输入新记录

    printf("请输入职工姓名：");
    scanf("%49s", employee[*count].name);
    printf("请输入基本工资：");
    scanf("%f", &employee[*count].basicSalary);
    printf("请输入职务工资：");
    scanf("%f", &employee[*count].positionSalary);
    printf("请输入岗位津贴：");
    scanf("%f", &employee[*count].allowance);
    printf("请输入医疗保险：");
    scanf("%f", &employee[*count].medicalInsurance);
    printf("请输入公积金：");
    scanf("%f", &employee[*count].providentFund);
    // }

    employee[*count].totalSalary = employee[*count].basicSalary + employee[*count].positionSalary +
        employee[*count].allowance - employee[*count].medicalInsurance - employee[*count].providentFund;
    (*count)++;
    //fseek(file, 0, SEEK_END);  // 将文件指针移动到文件末尾
    //fwrite(&newEmployee, sizeof(Employee), 1, file);

    printf("记录更新成功。\n");
    //}

    /*else {
        fseek(file, -(int)sizeof(Employee), SEEK_CUR);
        fwrite(employee, sizeof(Employee), 1, file);
        printf("记录更新成功。\n");
    }*/
}

void displayRecord(const Employee* employee, int count) {
    if (count == 0)
    {
        printf("还没有职员信息\n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        printf("ID号    姓名        基本工资    职务工资    津贴        医疗保险    公积金      总工资    \n");
        printf("%-8s%-12s%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f\n",
            employee[i].id, employee[i].name, employee[i].basicSalary, employee[i].positionSalary,
            employee[i].allowance, employee[i].medicalInsurance, employee[i].providentFund, employee[i].totalSalary);
    }

}

void modifyRecord(Employee* employee, int count) {
    /*if (file == NULL) {
        perror("文件指针为空");
        exit(EXIT_FAILURE);
    }*/

    char modifyId[10];
    printf("请输入要修改记录的职工ID号：");
    scanf("%s", modifyId);

    //Employee temp;
    //long position = -1;  // 记录匹配记录的位置

    //rewind(file);
    int i;
    //while (fread(&temp, sizeof(Employee), 1, file) == 1) {
    for (i = 0; i < count; i++)
    {
        if (strcmp(employee[i].id, modifyId) == 0) {
            /*position = ftell(file) - sizeof(Employee); */ // 记录匹配记录的位置
            break;
        }
    }
    // }
     //if (position != -1) {
     //    fseek(file, position, SEEK_SET);  // 将文件指针移动到匹配记录的位置

         // 显示修改前的记录
    printf("修改前的记录：\n");
    printf("ID号    姓名        基本工资    职务工资    津贴        医疗保险    公积金      总工资    \n");
    printf("%-8s%-12s%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f\n",
        employee[i].id, employee[i].name, employee[i].basicSalary, employee[i].positionSalary,
        employee[i].allowance, employee[i].medicalInsurance, employee[i].providentFund, employee[i].totalSalary);

    // 用户输入更新的数据
    printf("请输入职工姓名：");
    scanf("%s", employee[i].name);

    printf("请输入基本工资：");
    scanf("%f", &employee[i].basicSalary);

    printf("请输入职务工资：");
    scanf("%f", &employee[i].positionSalary);

    printf("请输入岗位津贴：");
    scanf("%f", &employee[i].allowance);

    printf("请输入医疗保险：");
    scanf("%f", &employee[i].medicalInsurance);

    printf("请输入公积金：");
    scanf("%f", &employee[i].providentFund);

    employee[i].totalSalary = employee[i].basicSalary + employee[i].positionSalary +
        employee[i].allowance - employee[i].medicalInsurance - employee[i].providentFund;

    // 显示修改后的记录
    printf("修改后的记录：\n");
    printf("ID号    姓名        基本工资    职务工资    津贴        医疗保险    公积金      总工资    \n");
    printf("%-8s%-12s%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f\n",
        employee[i].id, employee[i].name, employee[i].basicSalary, employee[i].positionSalary,
        employee[i].allowance, employee[i].medicalInsurance, employee[i].providentFund, employee[i].totalSalary);

    //fseek(file, position, SEEK_SET);  // 将文件指针再次移动到匹配记录的位置
    //fwrite(&temp, sizeof(Employee), 1, file);  // 写入更新后的记录

    printf("记录更新成功。\n");
    // }
     /*else {
         printf("未找到匹配的记录。\n");
     }*/
}

void searchRecord(Employee* employee, int count) {
    /* if (file == NULL) {
         perror("文件指针为空");
         exit(EXIT_FAILURE);
     }*/

     //if (searchName == NULL) {
    printf("请输入要查找的职工姓名：");
    char tempName[50];
    if (scanf("%49s", tempName) != 1) {
        perror("输入无效");
        exit(EXIT_FAILURE);
    }
    //searchName = tempName;
//  }

 //Employee temp;
    int found = 0;

    // rewind(file);
    int i;
    printf("匹配的记录：\n");
    //while (fread(&temp, sizeof(Employee), 1, file) == 1) {
    for (i = 0; i < count; i++)
    {
        if (strcmp(employee[i].name, tempName) == 0) {
            printf("ID号    姓名        基本工资    职务工资    津贴        医疗保险    公积金      总工资    \n");
            printf("%-8s%-12s%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f\n",
                employee[i].id, employee[i].name, employee[i].basicSalary, employee[i].positionSalary,
                employee[i].allowance, employee[i].medicalInsurance, employee[i].providentFund, employee[i].totalSalary);
            found = 1;
        }
    }
    //}

    if (found == 0) {
        printf("未找到匹配的记录。\n");
    }
}

void deleteRecord(Employee* employee, int* count) {
    /*if (file == NULL) {
        perror("文件指针为空");
        exit(EXIT_FAILURE);
    }*/

    //if (deleteId == NULL) {
    if (*count == 0)
    {
        printf("没有职员信息");
        return;
    }
    printf("请输入要删除记录的职工ID号：");
    char tempId[10];
    if (scanf("%9s", tempId) != 1) {
        perror("输入无效");
        exit(EXIT_FAILURE);
    }
    // }

     /*Employee temp;
     FILE* tempFile;*/
     //long int position;  // 保存文件指针位置
     /*if (tmpfile_s(&tempFile) != 0) {
         perror("无法创建临时文件");
         exit(EXIT_FAILURE);
     }*/

     // 保存文件指针位置
     //position = ftell(file);

     //rewind(file);
    int i;
    // while (fread(&temp, sizeof(Employee), 1, file) == 1) {
    for (i = 0; i < *count; i++)
    {
        if (strcmp(employee[i].id, tempId) == 0) {
            break;
        }
    }
    for (int t = i; t < *count - 1; t++)
    {
        employee[t].allowance = employee[t + 1].allowance;
        employee[t].basicSalary = employee[t + 1].basicSalary;
        strcpy(employee[t].id, employee[t + 1].id);
        employee[t].medicalInsurance = employee[t + 1].medicalInsurance;
        strcpy(employee[t].name, employee[t + 1].name);
        employee[t].positionSalary = employee[t + 1].positionSalary;
        employee[t].providentFund = employee[t + 1].providentFund;
        employee[t].totalSalary = employee[t + 1].totalSalary;
    }
    (*count)--;
    // } 

     //fclose(file);
     //if (fopen_s(&file, "employee_data.txt", "wb") != 0) {
     //    perror("文件打开失败");
     //    exit(EXIT_FAILURE);
    // }

     // 恢复文件指针位置
    // fseek(file, position, SEEK_SET);

    // rewind(tempFile);
    // while (fread(&temp, sizeof(Employee), 1, tempFile) == 1) {
    //     fwrite(&temp, sizeof(Employee), 1, file);
    // }

    // fclose(tempFile);
    printf("记录删除成功。\n");
}

void statistics(Employee* employee, int count) {
    /*if (file == NULL) {
        perror("文件指针为空");
        exit(EXIT_FAILURE);
    }*/

    //Employee temp;
    int numRecords = 0;
    float totalBasicSalary = 0.0;
    float totalPositionSalary = 0.0;
    float totalAllowance = 0.0;
    float totalMedicalInsurance = 0.0;
    float totalProvidentFund = 0.0;
    float totalTotalSalary = 0.0;

    float minSalaryRange = 1000.0;  // 最低工资范围
    float maxSalaryRange = 2000.0;  // 最高工资范围
    int countAbove3000 = 0;
    int countBetween2000And3000 = 0;
    int countBetween1000And2000 = 0;

    //rewind(file);

    //while (fread(&temp, sizeof(Employee), 1, file) == 1) {
    for (int i = 0; i < count; i++)
    {
        numRecords++;
        totalBasicSalary += employee[i].basicSalary;
        totalPositionSalary += employee[i].positionSalary;
        totalAllowance += employee[i].allowance;
        totalMedicalInsurance += employee[i].medicalInsurance;
        totalProvidentFund += employee[i].providentFund;
        totalTotalSalary += employee[i].totalSalary;

        // 统计工资范围
        float totalSalaryRange = employee[i].basicSalary + employee[i].positionSalary + employee[i].allowance;
        if (totalSalaryRange > 3000) {
            countAbove3000++;
        }
        else if (totalSalaryRange >= 2000) {
            countBetween2000And3000++;
        }
        else if (totalSalaryRange >= 1000) {
            countBetween1000And2000++;
        }
    }
    // }

     // (A) 计算各项工资平均工资及总工资
    float avgBasicSalary = totalBasicSalary / numRecords;
    float avgPositionSalary = totalPositionSalary / numRecords;
    float avgAllowance = totalAllowance / numRecords;
    float avgMedicalInsurance = totalMedicalInsurance / numRecords;
    float avgProvidentFund = totalProvidentFund / numRecords;
    float avgTotalSalary = totalTotalSalary / numRecords;

    printf("总记录数：%d\n", numRecords);
    printf("各项工资平均值：\n");
    printf("基本工资：%f\n", avgBasicSalary);
    printf("职务工资：%f\n", avgPositionSalary);
    printf("津贴：%f\n", avgAllowance);
    printf("医疗保险：%f\n", avgMedicalInsurance);
    printf("公积金：%f\n", avgProvidentFund);
    printf("总工资：%f\n", avgTotalSalary);

    // (B) 统计符合指定条件的工资范围内的职工人数及占总职工人数的百分比
    int totalCount = countAbove3000 + countBetween2000And3000 + countBetween1000And2000;
    float percentAbove3000 = (float)countAbove3000 / numRecords * 100;
    float percentBetween2000And3000 = (float)countBetween2000And3000 / numRecords * 100;
    float percentBetween1000And2000 = (float)countBetween1000And2000 / numRecords * 100;

    printf("\n工资范围统计：\n");
    printf("3000元以上的人数：%d，占总人数的 %.2f\n", countAbove3000, percentAbove3000);
    printf("3000元到2000元的人数：%d，占总人数的 %.2f\n", countBetween2000And3000, percentBetween2000And3000);
    printf("2000元到1000元的人数：%d，占总人数的 %.2f\n", countBetween1000And2000, percentBetween1000And2000);

    // (C) 按字符表格形式打印全部职工工资信息表及平均工资
    printf("\n全部职工工资信息表：\n");
    /*printf("%-10s%-10s%-15s%-15s%-10s%-15s%-10s%-15s\n",
        "ID号", "姓名", "基本工资", "职务工资", "津贴", "医疗保险", "公积金", "总工资");*/

        //rewind(file);
        //while (fread(&temp, sizeof(Employee), 1, file) == 1) {
    displayRecord(employee, count);
    // }

    printf("\n平均工资：\n");
    printf("基本工资：%f\n", avgBasicSalary);
    printf("职务工资：%f\n", avgPositionSalary);
    printf("津贴：%f\n", avgAllowance);
    printf("医疗保险：%f\n", avgMedicalInsurance);
    printf("公积金：%f\n", avgProvidentFund);
    printf("总工资：%f\n", avgTotalSalary);
}

void saveData(Employee* employee, int count) {
    /*if (file == NULL) {
        perror("文件指针为空");
        exit(EXIT_FAILURE);
    }*/

    //rewind(file);

    FILE* pwrite = fopen("employee_data.txt", "wb");
    if (pwrite == NULL)
    {
        perror("saveData");
        return;
    }
    //Employee temp;

    // 读取第一条记录
    //if (fread(&temp, sizeof(Employee), 1, file) != 1) {
        //printf("没有记录可保存。\n");
       // return;
   // }

    // 如果第一条记录全是0，表示没有有效记录，直接返回
    /*if (temp.basicSalary == 0 && temp.positionSalary == 0 && temp.allowance == 0 &&
        temp.medicalInsurance == 0 && temp.providentFund == 0 && temp.totalSalary == 0) {
        printf("没有记录可保存。\n");
        return;
    }*/

    // 输出表头信息
    //printf("%-10s%-10s%-15s%-15s%-10s%-15s%-10s%-15s\n",
    //    "ID号", "姓名", "基本工资", "职务工资", "津贴", "医疗保险", "公积金", "总工资");

    //// 将文件指针重新移动到文件开头
    //rewind(file);

    //// 输出记录
    //do {
    //    displayRecord(&temp);
    //} while (fread(&temp, sizeof(Employee), 1, file) == 1);


    for (int i = 0; i < count; i++)
    {
        fwrite(&employee[i], sizeof(Employee), 1, pwrite);
    }


    fclose(pwrite);
    pwrite = NULL;

    printf("数据保存成功。\n");
}
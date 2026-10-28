#include <stdio.h>
#include <locale.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char surname[50];
    char name[50];
    char patronymic[50];
    char position[50];
    float salary;
    Date birth_date;
} Employee;

int main() {
    setlocale(LC_ALL, "Russian");

    Employee employees[3] = {
        { "Иванов", "Иван", "Иванович", "Менеджер", 45000.0,{ 15, 5, 1985 } },
        { "Петров", "Петр", "Петрович", "Программист", 95000.0,{ 20, 10, 1998 } },
        { "Сидоров", "Алексей", "Сергеевич", "Стажер", 25000.0,{ 1, 1, 2001 } }
    };

    int num_employees = 3;
    float total_salary = 0.0;
    float avg_salary = 0.0;
    int current_year = 2024;

    for (int i = 0; i < num_employees; i++) {
        total_salary += employees[i].salary;
    }
    avg_salary = total_salary / num_employees;

    printf("Средняя зарплата по компании: %.2f руб.\n\n", avg_salary);
    printf("Сотрудники с зарплатой выше средней и возрастом до 30 лет:\n");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < num_employees; i++) {
        int age = current_year - employees[i].birth_date.year;

        if (employees[i].salary > avg_salary && age < 30) {
            printf("ФИО: %s %s %s\n",
                employees[i].surname, employees[i].name, employees[i].patronymic);
            printf("Должность: %s\n", employees[i].position);
            printf("Зарплата: %.2f руб.\n", employees[i].salary);
            printf("Дата рождения: %02d.%02d.%d (Возраст: %d)\n",
                employees[i].birth_date.day, employees[i].birth_date.month,
                employees[i].birth_date.year, age);
            printf("----------------------------------------------------------\n");
        }
    }

    return 0;
}

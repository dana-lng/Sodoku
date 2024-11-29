#include <stdio.h>

struct Person 
{
    char *name;
    int age;
    char gender;
};

void updatestruct(struct Person *person, int agebage, char *name1)
{
    person->age = agebage;
    person->name = name1;
}
int main()
{
    struct Person Nachbar;
    updatestruct(&Nachbar, 20, &"Anh");
                // *person = &Nachbar
    printf("%d, %s", Nachbar.age, Nachbar.name);
}


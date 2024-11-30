#include <stdio.h>

struct Person 
{
    char *name;
    int age;
    char gender;
};

void updatestruct(struct Person *person, int agebage, char *name1)
{                                                       //*name1 = &name1 = "Anh"
    person->age = agebage;
    person->name = name1;
    //*name = person->name
}
int main()
{
    struct Person Nachbar;
    updatestruct(&Nachbar, 20, "Anh");
                // *person = &Nachbar
    printf("%d, %s", Nachbar.age, Nachbar.name);
}


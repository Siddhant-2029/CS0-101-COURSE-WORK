#include<stdio.h>
void area_triangle(float base, float heigth);
int main(){
    float base=0.5, height=2;
    area_triangle(base,height);
    return 0;
}


void area_triangle(float base,float height){
    printf("area of the triangle is: " "%f", 0.5*base*height);
}

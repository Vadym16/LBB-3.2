#include <iostream>
#include <cmath>

using namespace std;

class Vector {
public:

    Vector() : arr{ 0, 0, 0 }, status(0) {
        count_ob++;
    }
    Vector(double a) : arr{a,a,a}, status(0){
        count_ob++;
    }
    Vector(const double* a) {
        if (a == NULL) {
            status = 1;
            arr[0] = arr[1] = arr[2] = 0;
        }
        else {
            arr[0] = a[0];
            arr[1] = a[1];
            arr[2] = a[2];
            status = 0;
        }
        count_ob++;
    }
    Vector(double x, double y, double z){
        arr[0] = x;
        arr[1] = y;
        arr[2] = z;

    }

    ~Vector() {
        if (status) {
            cout << "ВИявлено помилку вектора";
            cout << "Status: " << status;
        }
        count_ob--;
    }
    //Нада в коді
    void EROR() {
        cout << "Виявленно помилку";
    }
    double dov_vec() const {
        return sqrt(arr[0] * arr[0] + arr[1] * arr[1] + arr[2] * arr[2]);
    }


    void setdef(double a) {
        arr[0] = arr[1] = arr[2] = a;
    }

    //Вивод
    double getArr(int inx) {
        if (inx >= 0 and inx < 3) {
            return arr[inx];
        }
        else {
            EROR();
        }
    }
    void view() {
        cout << " Масив: ";
        cout << "[" << arr[0] << ", " << arr[1] << ", " << arr[2] << "]"<<endl;
    }

    //Знаки + - * /
    Vector plus(const Vector& b) {
        return Vector{ arr[0] + b.arr[0], arr[1] + b.arr[1], arr[2] + b.arr[2] };
    }
    Vector minus(const Vector& b) {
        return Vector{ arr[0] - b.arr[0], arr[1] - b.arr[1], arr[2] - b.arr[2] };
    }
    Vector dob(const Vector& b) {
        return Vector{ 
        arr[1] * b.arr[2] - arr[2] * b.arr[1],
        arr[2] * b.arr[0] - arr[0] * b.arr[2],
        arr[0] * b.arr[1] - arr[1] * b.arr[0]
           
        };
    }
    void dil(short c) {
        if (c == 0) {
            status = 1; 
        }
        else {
            arr[0] /= c;
            arr[1] /= c;
            arr[2] /= c;
        }
    }

    bool more(const Vector& b) {
        return dov_vec() > b.dov_vec();
    }

    bool less(const Vector& b) {
        return dov_vec() < b.dov_vec();
    }

    bool rivno(const Vector& b) {
        return dov_vec() == b.dov_vec(); 
    }



private:
    double arr[3];
    bool status = 0;
    int count_ob = 0;
};

void virno() {
    cout << "true" << endl;
}

void nevirno() {
    cout << "false" << endl;
}


int main()
{
    setlocale(LC_ALL, "ukr");

    Vector v1;
    Vector v2(1);
    Vector v3(1, 3, 5);
    v1.setdef(8);
    cout << "Вектор 1: "; v1.view();
    cout << "\nВектор 2: "; v2.view();
    cout << "\nВектор 3: "; v3.view();
   
    Vector dod, min, dob;

    dod = v1.plus(v2);
    min = v1.minus(v2);
    dob = v1.dob(v2);
    v1.dil(2);

    cout << "Додавання: "; dod.view();
    cout << "Віднімання: "; min.view();
    cout << "Множення: "; dob.view();
    cout << "Ділення: "; v1.view();

    if (v2.more(v3)) {
        virno();
    }
    else nevirno();

    if (v2.less(v3)) {
        virno();
    }
    else nevirno();

    if (v2.rivno(v3)) {
        virno();
    }
    else nevirno();

}


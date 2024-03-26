#include"matrix.h"
#include<cstdlib>
#include<iostream>
#include<ctime>
Matrix::Matrix(){
    this->N = 1;
    this->data = new double*[1];
    this->data[0] = new double[1];
    this->data[0][0] = 0.0;
    //std::cout<<"Matrix    "<<"1*1"<<"    is initialized!\n";
}
Matrix::Matrix(int n){
    this->N = n;
    this->data = new double*[this->N];
    for(int i = 0;i<this->N;i++)
        this->data[i] = new double[this->N];
    std::srand((unsigned)std::time(0));
    for(int i=0;i<this->N;i++)
        for(int j=0;j<this->N;j++){
            this->data[i][j]= (double)(rand()/(double)RAND_MAX);
        }
    //std::cout<<"Matrix    "<<N<<"*"<<N<<"    is initialized!\n";
}
Matrix::Matrix(int n,double init){
    this->N = n;
    this->data = new double*[this->N];
    for(int i = 0;i<this->N;i++)
        this->data[i] = new double[this->N];
    for(int i=0;i<this->N;i++)
        for(int j=0;j<this->N;j++){
            this->data[i][j]= init;
        }
    //std::cout<<"Matrix 0.0   "<<N<<"*"<<N<<"    is initialized!\n";
}
Matrix & Matrix::operator=(const Matrix &st){
    if(this == &st)
        return *this;
    for(int i=0;i<this->N;i++)
        delete [] this->data[i];
    delete [] this->data;
    this->N = st.N;
    this->data = new double*[this->N];
    for(int i = 0;i<N;i++)
        this->data[i] = new double[this->N];
    for(int i=0;i<this->N;i++)
        for(int j=0;j<this->N;j++)
            this->data[i][j]=st.data[i][j];
    return *this;
}
Matrix::~Matrix(){
    for(int i=0;i<this->N;i++)
        delete [] this->data[i];
    delete [] this->data;
}
void Matrix::add(int n, const Matrix &A, const Matrix &B, Matrix &R){
    for(int i=0; i<n; i++)
        for(int j=0;j<n;j++)
            R.data[i][j] = A.data[i][j] + B.data[i][j];
}
void Matrix::sub(int n, const Matrix &A, const Matrix &B, Matrix &R){
    for(int i=0; i<n; i++)
        for(int j=0;j<n;j++)
            R.data[i][j] = A.data[i][j] - B.data[i][j];
}
void Matrix::multiple(const Matrix &A,const Matrix &B,Matrix &C){
    for(int i=0;i<2;i++)
        for(int j =0;j<2;j++){
            C.data[i][j] = 0.0;
            for(int t = 0;t <2;t++){
                C.data[i][j] = C.data[i][j] + A.data[i][t]*B.data[t][j];
            }
        }
}
/*
void Matrix::strassen(int n, Matrix &A, Matrix &B, Matrix &C){
    double **A11,**A12,**A21,**A22;
    double **B11,**B12,**B21,**B22;
    double **C11,**C12,**C21,**C22;
    double **AA,**BB;
    double **M1,**M2,**M3,**M4,**M5,**M6,**M7;
    A11 = new double*[this->N];  //Memory malloc step
    A12 = new double*[this->N];
    A21 = new double*[this->N];
    A22 = new double*[this->N];
    B11 = new double*[this->N];
    B12 = new double*[this->N];
    B21 = new double*[this->N];
    B22 = new double*[this->N];
    C11 = new double*[this->N];
    C12 = new double*[this->N];
    C21 = new double*[this->N];
    C22 = new double*[this->N];
    A11 = new double*[this->N];
    AA  = new double*[this->N];
    BB  = new double*[this->N];
    M1  = new double*[this->N];
    M2  = new double*[this->N];
    M3  = new double*[this->N];
    M4  = new double*[this->N];
    M5  = new double*[this->N];
    M6  = new double*[this->N];
    M7  = new double*[this->N];
    for(int i=0;i<this->N;i++){
        A11[i] = new double[this->N];
        A12[i] = new double[this->N];
        A21[i] = new double[this->N];
        A22[i] = new double[this->N];
        B11[i] = new double[this->N];
        B12[i] = new double[this->N];
        B21[i] = new double[this->N];
        B22[i] = new double[this->N];
        C11[i] = new double[this->N];
        C12[i] = new double[this->N];
        C21[i] = new double[this->N];
        C22[i] = new double[this->N];
        A11[i] = new double[this->N];
        AA[i]  = new double[this->N];
        BB[i]  = new double[this->N];
        M1[i]  = new double[this->N];
        M2[i]  = new double[this->N];
        M3[i]  = new double[this->N];
        M4[i]  = new double[this->N];
        M5[i]  = new double[this->N];
        M6[i]  = new double[this->N];
        M7[i]  = new double[this->N];
    }
    if(n==2){
        multiple(A, B, C);
    }else{
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                A11[i][j] = A.data[i][j];
                A12[i][j] = A.data[i][j+n/2];
                A21[i][j] = A.data[i+n/2][j];
                A22[i][j] = A.data[i+n/2][j+n/2];
                B11[i][j] = B.data[i][j];
                B12[i][j] = B.data[i][j+n/2];
                B21[i][j] = B.data[i+n/2][j];
                B22[i][j] = B.data[i+n/2][j+n/2];
            }
        }
        sub(n/2, B12, B22, BB);
    }
}
*/
void Matrix::Normal_Multiple( Matrix &A, Matrix &B, Matrix &C){
    for(int i=0;i<A.N;i++)
        for(int j =0;j<A.N;j++){
            C.data[i][j] = 0.0;
            for(int t = 0;t <A.N;t++){
                C.data[i][j] = C.data[i][j] + A.data[i][t]*B.data[t][j];
            }
        }
}
void Matrix::call_divide_and_conquer(int n, Matrix &A, Matrix &B, Matrix &C){
    Matrix array[20]={
        Matrix(N,0.0), //A11 ->[0]
        Matrix(N,0.0), //A12 ->[1]
        Matrix(N,0.0), //A21 ->[2]
        Matrix(N,0.0), //A22 ->[3]
        Matrix(N,0.0), //B11 ->[4]
        Matrix(N,0.0), //B12 ->[5]
        Matrix(N,0.0), //B21 ->[6]
        Matrix(N,0.0), //B22 ->[7]
        Matrix(N,0.0), //C11 ->[8]
        Matrix(N,0.0), //C12 ->[9]
        Matrix(N,0.0), //C21 ->[10]
        Matrix(N,0.0), //C22 ->[11]
        Matrix(N,0.0), //M1  ->[12]
        Matrix(N,0.0), //M2  ->[13]
        Matrix(N,0.0), //M3  ->[14]
        Matrix(N,0.0), //M4  ->[15]
        Matrix(N,0.0), //M5  ->[16]
        Matrix(N,0.0), //M6  ->[17]
        Matrix(N,0.0), //M7  ->[18]
        Matrix(N,0.0)  //M8  ->[19]
    };
    Matrix::Divide_and_conquer(N,A,B,C,array);
}
void Matrix::Divide_and_conquer(int n, Matrix &A, Matrix &B, Matrix &C,Matrix (&array)[20]){
    if(n==2){
        multiple(A, B, C);
    }else{
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                array[0].data[i][j] = A.data[i][j];
                array[1].data[i][j] = A.data[i][j+n/2];
                array[2].data[i][j] = A.data[i+n/2][j];
                array[3].data[i][j] = A.data[i+n/2][j+n/2];
                array[4].data[i][j] = B.data[i][j];
                array[5].data[i][j] = B.data[i][j+n/2];
                array[6].data[i][j] = B.data[i+n/2][j];
                array[7].data[i][j] = B.data[i+n/2][j+n/2];
            }
        }
        Divide_and_conquer(n / 2, array[0], array[4], array[12],array); //M1=A11B11
        Divide_and_conquer(n / 2, array[1], array[6], array[13],array); //M2=A12B21
        Divide_and_conquer(n / 2, array[0], array[5], array[14],array); //M3=A11B12
        Divide_and_conquer(n / 2, array[1], array[7], array[15],array); //M4=A12B22
        Divide_and_conquer(n / 2, array[2], array[4], array[16],array); //M5=A21B11
        Divide_and_conquer(n / 2, array[3], array[6], array[17],array); //M6=A22B21
        Divide_and_conquer(n / 2, array[2], array[5], array[18],array); //M7=A21B12
        Divide_and_conquer(n / 2, array[3], array[7], array[19],array); //M8=A22B22
        //C11 = M1 + M2 
        add(n / 2, array[12], array[13], array[8]);
        //C12 = M3 + M4
        add(n / 2, array[14], array[15], array[9]);
        //C21 = M5 + M6
        add(n / 2, array[16],array[17], array[10]);
        //C22 = M7 + M8
        add(n / 2, array[18], array[18], array[11]);
        for(int i=0;i<n/2;i++)
            for(int j=0;j<n/2;j++){
                C.data[i][j] = array[8].data[i][j];
                C.data[i][j+n/2] = array[9].data[i][j];
                C.data[i+n/2][j] = array[10].data[i][j];
                C.data[i+n/2][j+n/2] = array[11].data[i][j];
            }
    }
}
void Matrix::call_strassen(int n, Matrix &A, Matrix &B, Matrix &C){
    Matrix array[21]={
        Matrix(N,0.0), //A11 ->[0]
        Matrix(N,0.0), //A12 ->[1]
        Matrix(N,0.0), //A21 ->[2]
        Matrix(N,0.0), //A22 ->[3]
        Matrix(N,0.0), //B11 ->[4]
        Matrix(N,0.0), //B12 ->[5]
        Matrix(N,0.0), //B21 ->[6]
        Matrix(N,0.0), //B22 ->[7]
        Matrix(N,0.0), //C11 ->[8]
        Matrix(N,0.0), //C12 ->[9]
        Matrix(N,0.0), //C21 ->[10]
        Matrix(N,0.0), //C22 ->[11]
        Matrix(N,0.0), //M1  ->[12]
        Matrix(N,0.0), //M2  ->[13]
        Matrix(N,0.0), //M3  ->[14]
        Matrix(N,0.0), //M4  ->[15]
        Matrix(N,0.0), //M5  ->[16]
        Matrix(N,0.0), //M6  ->[17]
        Matrix(N,0.0), //M7  ->[18]
        Matrix(N,0.0), //AA  ->[19]
        Matrix(N,0.0)  //BB  ->[20]
    };
    Matrix::Strassen(N,A,B,C,array);
}
void Matrix::Strassen(int n, Matrix &A, Matrix &B, Matrix &C,Matrix (&array)[21]){
    if(n==2){
        multiple(A, B, C);
    }else{
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                array[0].data[i][j] = A.data[i][j];
                array[1].data[i][j] = A.data[i][j+n/2];
                array[2].data[i][j] = A.data[i+n/2][j];
                array[3].data[i][j] = A.data[i+n/2][j+n/2];
                array[4].data[i][j] = B.data[i][j];
                array[5].data[i][j] = B.data[i][j+n/2];
                array[6].data[i][j] = B.data[i+n/2][j];
                array[7].data[i][j] = B.data[i+n/2][j+n/2];
            }
        }
        sub(n/2, array[5], array[7], array[20]);
        Strassen(n/2, array[0],array[20], array[12],array); //M1=A11(B12-B22)
        add(n / 2, array[0], array[1], array[19]);
        Strassen(n / 2, array[19], array[7], array[13],array); //M2=(A11+A12)B22
        add(n / 2, array[2], array[3], array[19]);
        Strassen(n / 2, array[19], array[4], array[14],array); //M3=(A21+A22)B11
        sub(n / 2, array[6], array[4], array[20]);
        Strassen(n / 2, array[3], array[20], array[15],array); //M4=A22(B21-B11)
        add(n / 2, array[0], array[3], array[19]);
        add(n / 2, array[4], array[7], array[20]);
        Strassen(n / 2, array[19], array[20], array[16],array); //M5=(A11+A22)(B11+B22)
        sub(n / 2, array[1], array[3], array[19]);
        add(n / 2, array[6], array[7], array[20]);
        Strassen(n / 2, array[19], array[20], array[17],array);  //M6=(A12-A22)(B21+B22)
        sub(n / 2, array[0], array[2], array[19]);
        add(n / 2, array[4], array[5], array[20]);
        Strassen(n / 2, array[19], array[20], array[18],array); //M7=(A11-A21)(B11+B12)

        //C11 = M5 + M4 - M2 + M6
        add(n / 2, array[16], array[15], array[19]);
        sub(n / 2, array[17], array[13], array[20]);
        add(n / 2, array[19], array[20], array[8]);

        //C12 = M1 + M2
        add(n / 2, array[12], array[13], array[9]);

        //C21 = M3 + M4
        add(n / 2, array[14], array[15], array[10]);

        //C22 = M5 + M1 - M3 - M7
        sub(n / 2, array[16], array[14], array[19]);
        sub(n / 2, array[12], array[18], array[20]);
        add(n / 2, array[19], array[20], array[11]);
        for(int i=0;i<n/2;i++)
            for(int j=0;j<n/2;j++){
                C.data[i][j] = array[8].data[i][j];
                C.data[i][j+n/2] = array[9].data[i][j];
                C.data[i+n/2][j] = array[10].data[i][j];
                C.data[i+n/2][j+n/2] = array[11].data[i][j];
            }
    }
}

std::ostream & operator<<(std::ostream & os, const Matrix &st){
    for(int i=0;i<st.N;i++){
        for(int j=0;j<st.N;j++)
            std::cout<<st.data[i][j]<<" ";
        std::cout<<std::endl;
    }
        
}

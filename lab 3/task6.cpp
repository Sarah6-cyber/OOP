#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class Matrix {
    int rows, cols;
    int **element;
    public:
    Matrix(){

    }
    Matrix(int rows, int cols){
        this->rows=rows;
        this->cols=cols;
        element=new int*[rows];
        for (int i=0; i<rows; i++){
            element[i]=new int[cols];
        }
    }

    ~Matrix(){
        for (int i=0; i<rows; i++){
            delete [] element[i];
        }
        delete [] element;
    }
    int get_rows(){
        return rows;
    }
    int get_cols(){
        return cols;
    }
    void settingElements(int i, int j, int num){
        if (i>=0 && i<rows && j>=0 && j<cols){
            element[i][j]=num;
        } else {
            cout<<"incorrect position entered!"<<endl;
        }
    }
    void displayMatrix(){
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                cout<<element[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    Matrix add(Matrix &m){
        if (rows!=m.get_rows() || cols!=m.get_cols()){
            cout<<"addition not applicable!"<<endl;
            exit(0);
        }
        Matrix result(rows, cols);
        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                result.settingElements(i, j, element[i][j]+m.element[i][j]);
            }
        }
        return result;
    }
    Matrix multiply(Matrix &m){
        if (cols!=m.get_rows()){
            cout<<"multiplication not applicable"<<endl;
            exit(0);
        }
        Matrix result(rows, m.get_cols());
        for (int i=0; i<rows; i++){
            for (int j=0; j<m.get_cols(); j++){
                result.settingElements(i, j, 0);
                for (int k=0; k<get_cols(); k++) {
                    result.element[i][j] += element[i][k] * m.element[k][j];
                }
            }
        }
        return result;
    }       
};

int main(int argc, char *argv[]) {
    int row_1=stoi(argv[1]);
    int column_1=stoi(argv[2]);
    int row_2=stoi(argv[3]);
    int column_2=stoi(argv[4]);
    Matrix m1(row_1, column_1);
    Matrix m2(row_2, column_2);
    int count=5;
    for (int i=0; i<row_1; i++){
        for (int j=0; j<column_1; j++){
            m1.settingElements(i, j, stoi(argv[count++]));
        }
    }
    for (int i=0; i<row_2; i++){
        for (int j=0; j<column_2; j++){
            m2.settingElements(i, j, stoi(argv[count++]));
        }
    }

    cout<<"matrix 1: "<<endl;
    m1.displayMatrix();
    cout<<"matrix 2: "<<endl;
    m2.displayMatrix();
    cout<<"adding matrices: " <<endl;
    cout<<"matrix 1 + matrix 2: "<<endl;
    m1.add(m2).displayMatrix();
    cout << "multiplying matrices: "<<endl;
    m1.multiply(m2).displayMatrix();
    return 0;
}

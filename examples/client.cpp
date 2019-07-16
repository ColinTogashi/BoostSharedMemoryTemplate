#include <BoostSharedMemoryTemplate/SharedMemory.hpp>
#include <Eigen/Dense>
#include <vector>
#include <iostream>

struct ExampleData {
    double x_value;
    double y_value;
    int    count;
    // double vector[2];
    // double *ptr;
    // double z_value;
};

int main() {
    SharedMemory<Eigen::Matrix<double,3,1>> eigen_shm = SharedMemory<Eigen::Matrix<double,3,1>>("TEST_EIGEN_DATA");
    SharedMemory<ExampleData> struct_shm = SharedMemory<ExampleData>("TEST_STRUCT_DATA");
    // SharedMemory<std::vector<double>> vector_shm = SharedMemory<std::vector<double>>("TEST_VECTOR_DATA");
    // SharedMemory<double*> dynamic_shm = SharedMemory<double*>("TEST_DYNAMIC_DATA");

    Eigen::Matrix<double,3,1> eigen_output = eigen_shm.GetData();
    ExampleData struct_output = struct_shm.GetData();
    // std::vector<double> vector_output = vector_shm.GetData();
    // double *dynamic_output = dynamic_shm.GetData();
    // Eigen::Matrix<double,3,1> dynamic_eigen_output = dyanmic_eigen_shm.GetData();

    std::cout << "Eigen values: " << eigen_output[0] << ", " << eigen_output[1] << ", " << eigen_output[2] << "\n";
    std::cout << "Struct values 1: " << struct_output.x_value << ", " << struct_output.y_value << ", " << struct_output.count << "\n";
    // std::cout << "Struct values 2: " << struct_output.vector[0] << ", " << struct_output.vector[1] << "\n";
    // std::cout << "Struct values 3: " << struct_output.ptr[0] << ", " << struct_output.ptr[1] << "\n";
    // std::cout << "Vector values: " << vector_output[0] << ", " << vector_output[1] << ", " << vector_output[2] << "\n";
    // std::cout << "Dynamic values: " << dynamic_output[0] << ", " << dynamic_output[1] << ", " << dynamic_output[2] << "\n";
    // std::cout << "Dynamic Eigen values: " << dynamic_eigen_output[0] << ", " << dynamic_eigen_output[1] << ", " << dynamic_output[2] << "\n";


    return 0;
}
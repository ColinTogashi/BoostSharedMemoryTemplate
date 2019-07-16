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
    std::shared_ptr<SharedMemory<std::array<double,4>>> ptr_shm;
    ptr_shm.reset(new SharedMemory<std::array<double,4>>("TEST_VECTOR_DATA_2"));

    SharedMemory<std::array<double,4>> vector_shm = SharedMemory<std::array<double,4>>("TEST_VECTOR_DATA");
    SharedMemory<Eigen::Matrix<double,3,1>> eigen_shm = SharedMemory<Eigen::Matrix<double,3,1>>("TEST_EIGEN_DATA");
    SharedMemory<ExampleData> struct_shm = SharedMemory<ExampleData>("TEST_STRUCT_DATA");
    SharedMemory<double *> dynamic_shm = SharedMemory<double*>("TEST_DYNAMIC_DATA");

    // SharedMemory<Eigen::Matrix<double, Eigen::Dynamic, 1>> dyanmic_eigen_shm = SharedMemory<Eigen::Matrix<double, Eigen::Dynamic, 1>>("TEST_DYNAMIC_EIGEN_DATA");
    // Eigen::Matrix<double, Eigen::Dynamic, 1> dyanmic_eigen;


    Eigen::Matrix<double,3,1> eigen_data = Eigen::Matrix<double,3,1>::Zero();
    eigen_data << 1.0, 2.31, 4.0;

    ExampleData struct_data = ExampleData();
    struct_data.x_value = 2.0;
    struct_data.y_value = -23.55;
    struct_data.count = 45;
    // struct_data.vector[0] = 1.222;
    // struct_data.vector[1] = 3.11;
    // double vector[] = {1.0, 3.33};
    // struct_data.ptr = vector;
    // struct_data.z_value = 34.33;

    double dynamic_data[] = {0.1, 0.3, 2.55};

    std::array<double, 4> vector_data;
    vector_data[0] = 43.221;
    vector_data[1] = 1.2333;
    vector_data[2] = 9.002;

    // dyanmic_eigen = Eigen::Matrix<double, 3, 1>(vector_data.data());

    eigen_shm.SetData(eigen_data);
    struct_shm.SetData(struct_data);
    dynamic_shm.SetData(dynamic_data);
    vector_shm.SetData(vector_data);


    // dyanmic_eigen_shm.SetData(dyanmic_eigen);

    Eigen::Matrix<double,3,1> eigen_output = eigen_shm.GetData();
    ExampleData struct_output = struct_shm.GetData();
    std::array<double,4> vector_output = vector_shm.GetData();
    double *dynamic_output = dynamic_shm.GetData();
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
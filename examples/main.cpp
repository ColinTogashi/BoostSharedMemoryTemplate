#include <BoostSharedMemoryTemplate/SharedMemory.hpp>
#include <Eigen/Dense>
#include <iostream>

struct ExampleData {
    double x_value;
    double y_value;
    int    count;
};

int main() {
    Eigen::Matrix<double,3,1> eigen_data = Eigen::Matrix<double,3,1>::Zero();
    ExampleData struct_data = ExampleData();

    SharedMemory<Eigen::Matrix<double,3,1>> eigen_shm = SharedMemory<Eigen::Matrix<double,3,1>>("TEST_eigen_data");
    SharedMemory<ExampleData> struct_shm = SharedMemory<ExampleData>("TEST_struct_data");
    

    eigen_data << 1.0, 2.31, 4.0;
    struct_data.x_value = 2.0;
    struct_data.x_value = -23.55;
    struct_data.count = 45;

    eigen_shm.SetData(eigen_data);
    struct_shm.SetData(struct_data);

    ExampleData struct_output = struct_shm.GetData();
    Eigen::Matrix<double,3,1> eigen_output = eigen_shm.GetData();

    std::cout << "Struct values: " << struct_output.x_value << ", " << struct_output.y_value << ", " << struct_output.count << "\n";
    std::cout << "Eigen values: " << eigen_output[0] << ", " << eigen_output[1] << ", " << eigen_output[2] << "\n";

    return 0;
}
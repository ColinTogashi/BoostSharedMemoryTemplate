#ifndef SHARED_MEMORY_HPP_
#define SHARED_MEMORY_HPP_

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/named_semaphore.hpp>

// TODO: Pick a namespace

template<class T>
class SharedMemory {

private:
    const std::string robot_mem_name_;

protected:
    // TODO: make these smart pointers?
    T *mem_ptr_;
    boost::interprocess::named_semaphore *mem_semaphore_ptr_;
    boost::interprocess::mapped_region *mem_region_ptr_;

public:
    SharedMemory(const std::string &robot_mem_name);
    ~SharedMemory();
    virtual T GetData();
    virtual void SetData(const T &data);

};

#include "SharedMemory.tpp"

#endif
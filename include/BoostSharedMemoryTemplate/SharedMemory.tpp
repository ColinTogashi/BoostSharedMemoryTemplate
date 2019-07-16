// TODO: Pick a namespace

template<class T>
SharedMemory<T>::SharedMemory(const std::string &robot_mem_name) :
        robot_mem_name_(robot_mem_name)
{
    // Names of the shared memory and semaphore for
    std::string mem_name_ = robot_mem_name_ + "_mem";
    std::string sem_name = robot_mem_name_ + "_lock";

    // Create shared memory object associated with the python mapping
    boost::interprocess::shared_memory_object shm (boost::interprocess::open_or_create, mem_name_.c_str(), boost::interprocess::read_write);

    // Sets the size of the shared memory object to the size of the data type. Needed for next line
    shm.truncate(sizeof(T));

    // Map to the entire region
    mem_region_ptr_.reset(new boost::interprocess::mapped_region(shm, boost::interprocess::read_write));
    
    // Create the pointers to the memory block and the semaphore
    mem_ptr_ = static_cast<T*>(mem_region_ptr_->get_address());
    mem_semaphore_ptr_.reset(new boost::interprocess::named_semaphore(boost::interprocess::open_or_create, sem_name.c_str(), 1));

};

template<class T>
T SharedMemory<T>::GetData() {
    // create a new data object
    T data;

    // get the semaphore and copy data into the object
    mem_semaphore_ptr_->wait();
    memcpy(&data, mem_ptr_, sizeof(T));
    mem_semaphore_ptr_->post();

    return data;
}

template<class T>
void SharedMemory<T>::SetData(const T &data) {
    // get the semaphore and copy data into the shared memory
    mem_semaphore_ptr_->wait();
    memcpy(mem_ptr_, &data, sizeof(T));
    mem_semaphore_ptr_->post();
}
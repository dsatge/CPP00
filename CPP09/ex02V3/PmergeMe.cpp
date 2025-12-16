# include "PmergeMe.hpp"

bool    is_ValidDigit(std::string element)
{
    std::stringstream   ss(element);
    double              nbr;
    ss >> nbr;
    if (ss.fail())
        throw   PmergeMe::UnautorizedCharacter();
    if (nbr < 0 || nbr > INT_MAX)
        throw   PmergeMe::ValueOutOfBound();
    return (true);
}

PmergeMe::PmergeMe(std::string line)
{
    std::string numberline;
    std::stringstream       ss(line);
    while (getline(ss, numberline, ' '))
    {
        if (is_ValidDigit(numberline) == true)
        {
            std::stringstream ss(numberline);
            int number;
            ss >> number;
            _Darray.push_back(number);
            _Varray.push_back(number);
        }
    }
}

PmergeMe::PmergeMe(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
    {
        if (is_ValidDigit(argv[i]) == true)
        {
            std::stringstream ss(argv[i]);
            int number;
            ss >> number;
            _Darray.push_back(number);
            _Varray.push_back(number);
        }
    }
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    this->_Darray = other._Darray;
    this->_Varray = other._Varray;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->_Darray = other._Darray;
        this->_Varray = other._Varray;
    }
    return (*this);
}

PmergeMe::~PmergeMe(void)
{
    return ;
}

void    primarySort_Vector(int left_start, int mid, int right_end
    ,std::vector<std::pair<int, int> > &array)
{
    int l = left_start;
    int r = mid;
    int i = left_start;
    std::vector<std::pair<int, int> > tmp(array);

    // Sort
    while (l < mid && r < right_end)
    {
        if (tmp[l].first < tmp[r].first)
        {
            array[i] = tmp[l];
            l++;
        }
        else
        {
            array[i] = tmp[r];
            r++;
        }
        i++;
    }
    // Sort left-overs
    while (l < mid)
    {
        array[i] = tmp[l];
        l++;
        i++;
    }
    while (r < right_end)
    {
        array[i] = tmp[r];
        r++;
        i++;
    }
}

void    primarySort_Deque(int left_start, int mid, int right_end
    ,std::deque<std::pair<int, int> > &array)
{
    int l = left_start;
    int r = mid;
    int i = left_start;
    std::deque<std::pair<int, int> > tmp(array);

    // Sort
    while (l < mid && r < right_end)
    {
        if (tmp[l].first < tmp[r].first)
        {
            array[i] = tmp[l];
            l++;
        }
        else
        {
            array[i] = tmp[r];
            r++;
        }
        i++;
    }
    // Sort left-overs
    while (l < mid)
    {
        array[i] = tmp[l];
        l++;
        i++;
    }
    while (r < right_end)
    {
        array[i] = tmp[r];
        r++;
        i++;
    }
}

void    mergeSort_Vector(std::vector<std::pair<int, int> > &array, int start, int end)
{
    int segment_len = end - start;
    if (segment_len <= 1)
        return ;
    int left_start = start;
    int mid = start + (end - start) / 2;
    int right_end = end;

    mergeSort_Vector(array, left_start, mid);
    mergeSort_Vector(array, mid, right_end);
    primarySort_Vector(left_start, mid, right_end, array);

    // Affichage: //
    // std::vector<int>::iterator it = array.begin();
    // std::cout << "\nsorted largest values:\n";
    // for (; it != array.end(); it++)
    //     std::cout << " " << *it;
    ////////////////
}

void    mergeSort_Deque(std::deque<std::pair<int, int> > &array, int start, int end)
{
    int segment_len = end - start;
    if (segment_len <= 1)
        return ;
    int left_start = start;
    int mid = start + (end - start) / 2;
    int right_end = end;

    mergeSort_Deque(array, left_start, mid);
    mergeSort_Deque(array, mid, right_end);
    primarySort_Deque(left_start, mid, right_end, array);

    // Affichage: //
    // std::Deque<int>::iterator it = array.begin();
    // std::cout << "\nsorted largest values:\n";
    // for (; it != array.end(); it++)
    //     std::cout << " " << *it;
    ////////////////
}

std::vector<int> jacobsthalIndex_Vector(int elements, std::vector<int> &jIndex)
{
    jIndex.push_back(0);
    if (elements == 0)
        return jIndex;
    jIndex.push_back(1);
    if (elements == 1)
        return jIndex;
    int J_2 = 0;
    int J_1 = 1;
    int Jn = 0;
    for (; Jn < elements;)
    {
        Jn = J_1 + (2 * J_2);
        J_2 = J_1;
        J_1 = Jn;
        if (Jn < elements)
            jIndex.push_back(Jn);
    }
    return (jIndex);
}

std::deque<int> jacobsthalIndex_Deque(int elements, std::deque<int> &jIndex)
{
    jIndex.push_back(0);
    if (elements == 0)
        return jIndex;
    jIndex.push_back(1);
    if (elements == 1)
        return jIndex;
    int J_2 = 0;
    int J_1 = 1;
    int Jn = 0;
    for (; Jn < elements;)
    {
        Jn = J_1 + (2 * J_2);
        J_2 = J_1;
        J_1 = Jn;
        if (Jn < elements)
            jIndex.push_back(Jn);
    }
    return (jIndex);
}

void    binaryInsert_Vector(std::vector<int> &sortedArray, int value)
{
    if (sortedArray.empty())
    {
        sortedArray.push_back(value);
        return ;
    }

    int left = 0;
    int right = sortedArray.size();

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (sortedArray[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    sortedArray.insert(sortedArray.begin() + left, value);
}

void    binaryInsert_Deque(std::deque<int> &sortedArray, int value)
{
    if (sortedArray.empty())
    {
        sortedArray.push_back(value);
        return ;
    }

    int left = 0;
    int right = sortedArray.size();

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (sortedArray[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    sortedArray.insert(sortedArray.begin() + left, value);
}

void    insertBinarySearch_Vector(std::vector<std::pair<int, int> > &Array, std::vector<int> &sortedArray
        , int leftoverValue)
{
    int toInsertArraySize = Array.size();
    std::vector<int> toInsertArray;
    for (int i = 0; i < toInsertArraySize; i++)
    {
        sortedArray.push_back(Array[i].first);
        toInsertArray.push_back(Array[i].second);
    }
    std::vector<int> jacIndex;
    jacobsthalIndex_Vector(toInsertArraySize, jacIndex);
    if (toInsertArraySize > 0)
        binaryInsert_Vector(sortedArray, toInsertArray[0]);
    for (int i = jacIndex.size() - 1; i > 0; --i)
    {
        int start = jacIndex[i - 1];
        int end = jacIndex[i];

        if (end > toInsertArraySize)
            end = toInsertArraySize;
        for (int j = end; j > start; --j)
        {
            if (j < toInsertArraySize && j > 0)
            binaryInsert_Vector(sortedArray, toInsertArray[j]);
        }
    }
    int last = jacIndex.back();
    for (int i = (last + 1); i < toInsertArraySize; ++i)
            binaryInsert_Vector(sortedArray, toInsertArray[i]);
    if (leftoverValue >= 0)
        binaryInsert_Vector(sortedArray, leftoverValue);
}

void    insertBinarySearch_deque(std::deque<std::pair<int, int> > &Array, std::deque<int> &sortedArray
        , int leftoverValue)
{
    int toInsertArraySize = Array.size();
    std::deque<int> toInsertArray;
    for (int i = 0; i < toInsertArraySize; i++)
    {
        sortedArray.push_back(Array[i].first);
        toInsertArray.push_back(Array[i].second);
    }
    std::deque<int> jacIndex;
    jacobsthalIndex_Deque(toInsertArraySize, jacIndex);
    if (toInsertArraySize > 0)
        binaryInsert_Deque(sortedArray, toInsertArray[0]);
    for (int i = jacIndex.size() - 1; i > 0; --i)
    {
        int start = jacIndex[i - 1];
        int end = jacIndex[i];

        if (end > toInsertArraySize)
            end = toInsertArraySize;
        for (int j = end; j > start; --j)
        {
            if (j < toInsertArraySize && j > 0)
            binaryInsert_Deque(sortedArray, toInsertArray[j]);
        }
    }
    int last = jacIndex.back();
    for (int i = (last + 1); i < toInsertArraySize; ++i)
            binaryInsert_Deque(sortedArray, toInsertArray[i]);
    if (leftoverValue >= 0)
        binaryInsert_Deque(sortedArray, leftoverValue);
}


void    algo_Vector(std::vector<int> &array)
{
    int len_array = array.size();
    std::vector<std::pair<int, int> > pairedAssorted_array;
    int leftoverValue = -1;
    if (len_array % 2 != 0)
    {
        leftoverValue = array[len_array - 1];
        len_array--;
    }
    for (int i = 0; i < len_array; i += 2)
    {
        int largest;
        int smallest;
        if (array[i] > array[i + 1])
        {
            largest = array[i];
            smallest = array[i + 1];
        }
        else
        {
            largest = array[i + 1];
            smallest = array[i];
        }
        pairedAssorted_array.push_back(std::make_pair(largest, smallest));

    }
    mergeSort_Vector(pairedAssorted_array, 0, pairedAssorted_array.size());
    std::vector<int> sortedArray;
    insertBinarySearch_Vector(pairedAssorted_array, sortedArray, leftoverValue);
    std::vector<int>::iterator itlarge = sortedArray.begin();
    for (; itlarge != sortedArray.end(); itlarge++)
    {
        std::cout << " " << *itlarge;
    }
}

void    algo_deque(std::deque<int> &array)
{
    int len_array = array.size();
    std::deque<std::pair<int, int> > pairedAssorted_array;
    int leftoverValue = -1;
    if (len_array % 2 != 0)
    {
        leftoverValue = array[len_array - 1];
        len_array--;
    }
    for (int i = 0; i < len_array; i += 2)
    {
        int largest;
        int smallest;
        if (array[i] > array[i + 1])
        {
            largest = array[i];
            smallest = array[i + 1];
        }
        else
        {
            largest = array[i + 1];
            smallest = array[i];
        }
        pairedAssorted_array.push_back(std::make_pair(largest, smallest));

    }
    mergeSort_Deque(pairedAssorted_array, 0, pairedAssorted_array.size());
    std::deque<int> sortedArray;
    insertBinarySearch_deque(pairedAssorted_array, sortedArray, leftoverValue);
    std::deque<int>::iterator itlarge = sortedArray.begin();
    for (; itlarge != sortedArray.end(); itlarge++)
    {
        std::cout << "";
    }
}

double  calculateTime(struct timeval start, struct timeval end)
{
    long seconds = end.tv_sec - start.tv_sec;
    long microsec = end.tv_usec - start.tv_usec;
    return (seconds + (microsec * 1e-6));
}

void    PmergeMe::sortFJohnosonAlgo(void)
{
    std::vector<int>::iterator it = _Varray.begin();
    std::cout << "Before: ";
    while (it < _Varray.end())
    {
        std::cout << " " << *it;
        it++;
    }
    std::cout << "\nAfter:  ";

    struct timeval startTime_Vector;
    struct timeval endTime_Vector;
    gettimeofday(&startTime_Vector, NULL);
    algo_Vector(_Varray);
    gettimeofday(&endTime_Vector, NULL);

    struct timeval startTime_Deque;
    struct timeval endTime_Deque;
    gettimeofday(&startTime_Deque, NULL);
    algo_deque(_Darray);
    gettimeofday(&endTime_Deque, NULL);

    double time_vector = calculateTime(startTime_Vector, endTime_Vector);
    double time_deque = calculateTime(startTime_Deque, endTime_Deque);
    std::cout << "\nTime to process a range of " << _Varray.size() << " elements with " << CYAN << "std::vector" << RESET 
            << ": " << std::fixed << std::setprecision(6) << time_vector << " us" << std::endl;
    std::cout << "Time to process a range of " << _Darray.size() << " elements with " << CYAN << "std::deque" << RESET 
            << ": " << std::fixed << std::setprecision(6) << time_deque << " us" << std::endl;
}

// const char* PmergeMe::NegativeValues::what() const throw()
// {
//     return ("Values must be positive");
// }

const char* PmergeMe::UnautorizedCharacter::what() const throw()
{
    return ("Values must be positive numbers only");
}

const char* PmergeMe::ValueOutOfBound::what() const throw()
{
    return ("Value out of bound");
}
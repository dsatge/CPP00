# include "PmergeMe.hpp"

bool    is_ValidDigit(std::string element)
{
    std::stringstream   ss(element);
    double              nbr;
    ss >> nbr;
    if (!nbr)
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
    ,std::vector<int> &array)
{
    int l = left_start;
    int r = mid;
    int i = left_start;
    std::vector<int> tmp(array);

    // Sort
    while (l < mid && r < right_end)
    {
        if (tmp[l] < tmp[r])
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

void    mergeSort_Vector(std::vector<int> &array, int start, int end)
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

void    insertBinarySearch_Vector(std::vector<int> &sortedArray
    ,std::vector<int> &toInsertArray)
{
    int index = 0;
    int toInsertArraySize = toInsertArray.size();
    int left = 0;
    int right = sortedArray.size();
    int mid = (left + right) / 2;
    // Affichage: //
    std::vector<int>::iterator it = sortedArray.begin();
    std::cout << "\nsorted largest values:\n";
    for (; it != sortedArray.end(); it++)
        std::cout << " " << *it;
    std::cout << "\n";
    std::vector<int>::iterator it2 = toInsertArray.begin();
    std::cout << "\nto insert values:\n";
    for (; it2 != toInsertArray.end(); it2++)
        std::cout << " " << *it2;
    std::cout << "\n";
    //////////////

    while (index < toInsertArraySize)
    {
        std::cout << RED << " mid = " << mid << " mid value = " << sortedArray[mid] << " value to insert = " << toInsertArray[index] << RESET << std::endl;
        if (toInsertArray[index] == sortedArray[mid])
        {
            sortedArray.insert(sortedArray.begin() + mid, toInsertArray[index]);
            index++;
        }
        else if (toInsertArray[index] > sortedArray[mid])
        {
            std::cout << GREEN << "to Insert Array[index] = " << toInsertArray[index]
                    << " is bigger than sortedArray[mid] " << sortedArray[mid] << RESET << std::endl;
            left = mid;
            mid = (left + right) / 2;
        }
        else if (toInsertArray[index] < sortedArray[mid])
        {
            std::cout << MAGENTA << "to Insert Array[index] = " << toInsertArray[index]
                    << " is smaller than sortedArray[mid] " << sortedArray[mid] << RESET << std::endl;
            right = mid;
            mid = (left + right) / 2;
        }
        if (right - left == 1 || right - left == 0 || left - right == 1 || left - right == 0 )
        {
            std::cout << "check\nleft = " << left << " : " << sortedArray[left]
                    << " right = " << right << " : " << sortedArray[right] 
                    << " mid = " << mid << std::endl;
            sortedArray.insert(sortedArray.begin() + mid + 1, toInsertArray[index]);
            index++;
            left = 0;
            right = sortedArray.size();
            mid = (left + right) / 2;
            it = sortedArray.begin();
            for (; it != sortedArray.end(); it++)
                std::cout << " " << *it;
            std::cout << "\n";
        }
    }
}

void    algo_Vector(std::vector<int> array)
{
    int len_array = array.size();
    std::vector<int> largest_array;
    std::vector<int> other_array;
    for (int i = 0; i < (len_array - 1); i++)
    {
        if (i % 2 != 0)
            i++;
        if (array[i] > array[i + 1])
        {
            largest_array.push_back(array[i]);
            if (array[i + 1])
                other_array.push_back(array[i + 1]);
        }
        else
        {
            largest_array.push_back(array[i + 1]);
            if (array[i + 1])
            other_array.push_back(array[i]);
        }

    }
    mergeSort_Vector(largest_array, 0, largest_array.size());
    insertBinarySearch_Vector(largest_array, other_array);
    std::vector<int>::iterator itlarge = largest_array.begin();
    // std::cout << "largest :\n";
    for (; itlarge != largest_array.end(); itlarge++)
    {
        std::cout << CYAN << " " << *itlarge << RESET;
    }
    // std::vector<int>::iterator itsother = other_array.begin();
    // std::cout << "other :\n";
    // for (; itsother != other_array.end(); itsother++)
    // {
    //     std::cout << " " << *itsother;
    // }
}

// void    merge_Deque(std::deque<int> array)
// {

// }

void    PmergeMe::sortFJohnosonAlgo(void)
{
    std::vector<int>::iterator it = _Varray.begin();
    std::cout << "Before: ";
    while (it < _Varray.end())
    {
        std::cout << " " << *it;
        it++;
    }

    std::cout << "\nAfter: ";
    algo_Vector(_Varray);
    while (it < _Varray.end())
    {
        std::cout << " " << *it;
        it++;
    }
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
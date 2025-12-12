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

std::vector<int> jacobsthalIndex(int elements, std::vector<int> &jIndex)
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

void    insertBinarySearch_Vector(std::vector<std::pair<int, int> > &Array, std::vector<int> &sortedArray)
{
    int index = 0;
    int toInsertArraySize = Array.size();
    std::vector<int> toInsertArray;
    int i = 0;
    for (std::vector<std::pair<int, int> >::iterator it = Array.begin(); it != Array.end(); it++)
    {
        sortedArray.push_back(Array[i].first);
        toInsertArray.push_back(Array[i].second);
        i++;
    }
    std::vector<int> jacIndex;
    jacobsthalIndex(toInsertArraySize, jacIndex);
    std::vector<int>::iterator itj = jacIndex.begin();
    std::cout << MAGENTA << "\nsorted largest values:\n";
    for (; itj != jacIndex.end(); itj++)
        std::cout << " " << *itj;
    std::cout << RESET << "\n";
    int left = 0;
    int right = sortedArray.size();
    int mid = (left + right) / 2;

    // Affichage: //
    // std::vector<int>::iterator it = sortedArray.begin();
    // std::cout << "\nsorted largest values:\n";
    // for (; it != sortedArray.end(); it++)
    //     std::cout << " " << *it;
    // std::cout << "\n";
    // std::vector<int>::iterator it2 = toInsertArray.begin();
    // std::cout << "\nto insert values:\n";
    // for (; it2 != toInsertArray.end(); it2++)
    //     std::cout << " " << *it2;
    // std::cout << "\n";
    ////////////

    while (index < toInsertArraySize)
    {
        if (toInsertArray[index] == sortedArray[mid])
        {
            sortedArray.insert(sortedArray.begin() + mid, toInsertArray[index]);
            index++;
            left = 0;
            right = sortedArray.size();
            mid = (left + right) / 2;
        }
        else if (toInsertArray[index] > sortedArray[mid])
        {
            left = mid;
            mid = (left + right) / 2;
        }
        else if (toInsertArray[index] < sortedArray[mid])
        {
            right = mid;
            mid = (left + right) / 2;
        }
        if (right - left == 1 || right - left == 0 || left - right == 1 || left - right == 0 )
        {
            if ((sortedArray[left] < toInsertArray[index]) && (sortedArray[right] > toInsertArray[index]))
                sortedArray.insert(sortedArray.begin() + mid + 1, toInsertArray[index]);
            else if (sortedArray[left] < toInsertArray[index])
                sortedArray.insert(sortedArray.begin() + left, toInsertArray[index]);
            else if (sortedArray[right] > toInsertArray[index])
                sortedArray.insert(sortedArray.begin() + mid, toInsertArray[index]);
            index++;
            left = 0;
            right = sortedArray.size();
            mid = (left + right) / 2;
        }
    }
}

void    algo_Vector(std::vector<int> &array)
{
    int len_array = array.size();
    std::vector<std::pair<int, int> > pairedAssorted_array;
    int largest;
    int smallest;
    int odd;
    for (int i = 0; i < (len_array - 1); i++)
    {
        if (i % 2 != 0)
            i++;
        if (!array[i + 1])
            odd = array[i];
        else if (array[i] > array[i + 1])
        {
            largest = array[i];
            smallest = array[i + 1];
            pairedAssorted_array.push_back(std::make_pair(largest, smallest));
        }
        else
        {
            largest = array[i + 1];
            smallest = array[i];
            pairedAssorted_array.push_back(std::make_pair(largest, smallest));
        }

    }
    mergeSort_Vector(pairedAssorted_array, 0, pairedAssorted_array.size());
    std::vector<int> sortedArray;
    insertBinarySearch_Vector(pairedAssorted_array, sortedArray);
    std::vector<int>::iterator itlarge = sortedArray.begin();
    for (; itlarge != sortedArray.end(); itlarge++)
    {
        std::cout << " " << *itlarge;
    }
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
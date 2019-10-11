#include "algorithm_sort.h"

void bubbleSort(vector<int> &ivec, int len)
{
    if(len < 2)
        return ;
    int temp;
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = 0; j < len - i - 1; j++)
        {
            if(ivec[j + 1] < ivec[j])
            {
                temp = ivec[j + 1];
                ivec[j + 1] = ivec[j];
                ivec[j] = temp;
            }
        }
    }
}

void insertSort(vector<int> &ivec, int len)
{
    if(len < 2)
        return ;
    int temp;
    for(int i = 1; i < len; ++i)
    {
        temp = ivec[i];
        int j = i - 1;
        while(j >= 0 && ivec[j] > temp)
        {
            ivec[j + 1] = ivec[j--];
        }
        ivec[j + 1] = temp;
    }
}

int division(vector<int> &ivec, int left, int right)
{
    int temp = ivec[left];
    while(left < right)
    {
        while(left < right && temp <= ivec[right])
            right--;
        ivec[left] = ivec[right];
        while(left < right && temp >= ivec[left])
            left++;
        ivec[right] = ivec[left];
    }
    ivec[left] = temp;
    return left;
}

void QuickSort(vector<int> &ivec, int left, int right)
{
    if(left < right)
    {
        int temp = division(ivec, left, right);
        QuickSort(ivec, left, temp - 1);
        QuickSort(ivec, temp + 1, right);
    }
}

void HeapAdjust(vector<int> &ivec, int parent, int len)
{
    int child = parent * 2 + 1;
    int temp = ivec[parent];
    while(child < len)
    {
        if(child + 1 < len && ivec[child] < ivec[child + 1])
            child++;
        if(temp >= ivec[child])
            break;
        ivec[parent] = ivec[child];
        parent = child;
        child = parent * 2 + 1;
    }
    ivec[parent] = temp;
}

void HeadSort(vector<int> &ivec, int len)
{
    for(int i = len / 2 - 1; i >= 0; --i)
    {
        HeapAdjust(ivec, i, len);
    }
    for(int i = len - 1; i > 0; --i)
    {
        swap(ivec[0], ivec[i]);
        HeapAdjust(ivec, 0, i);
    }
}

void Merge(vector<int> &ivec, vector<int> new_ivec, int left, int mid, int right)
{
    int start = left, front = mid + 1;
    int i = 0;
    while(start <= mid && front <= right)
    {
        if(ivec[start] > ivec[front])
        {
            new_ivec[i++] = ivec[front++];
        }
        else
        {
            new_ivec[i++] = ivec[start++];
        }
    }
    while(start <= mid)
    {
        new_ivec[i++] = ivec[start++];
    }
    while(front <= right)
    {
        new_ivec[i++] = ivec[front++];
    }
    i = 0;
    for(int j = left; j <= right; ++j)
    {
        ivec[j] = new_ivec[i++];
    }
}

void MergeSort(vector<int> &ivec, vector<int> new_ivec, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(ivec, new_ivec, left, mid);
        MergeSort(ivec, new_ivec, mid + 1, right);
        Merge(ivec, new_ivec, left, mid, right);
    }
}

void mergesort(vector<int> &ivec, int len)
{
    vector<int> new_ivec(len);
    MergeSort(ivec, new_ivec, 0, len - 1);
}

void SelectSort(vector<int> &ivec, int len)
{
    int min;
    for(int i = 0; i < len - 1; ++i)
    {
        min = i;
        for(int j = i + 1; j < len; ++j)
        {
            if(ivec[j] < ivec[min])
            {
                min = j;
            }
        }
        swap(ivec[i], ivec[min]);
    }
}
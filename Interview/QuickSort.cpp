template <typename T>
void QuickSort(T arr[], int n)   //快速排序
{
    QSpartition(arr, 0, n - 1);
    InsertSort(arr, n);          //最后用插入排序对整个数组排序
}
 
template <typename T>
void QSpartition(T arr[], int low, int high)     //快速排序递归函数
{
     
//    if (low >= high)     //有插入排序，不需要这句
//        continue;
     
    const int min_insert = 128;
    if (high - low < min_insert)  //数据小于一定数量的时候用直接插入排序
    {
        return;  //最后用插入排序对整个数组排序
    }
 
    int i, j;
    T temp;
     
    //下面一段是前中后3个数据进行插入排序
    i = (low + high) / 2;
    if (arr[i] < arr[low])
    {
        temp = arr[i];
        arr[i] = arr[low];
        arr[low] = temp;
    }
    if (arr[high] < arr[i])
    {
        temp = arr[high];
        arr[high] = arr[i];
        arr[i] = temp;
        if (arr[i] < arr[low])
        {
            temp = arr[i];
            arr[i] = arr[low];
            arr[low] = temp;
        }
    }
//    if (high - low < 3)   //小区间用插入排序，这里就不需要判断了
//        return;           //不用插入排序，只有2个数据的时候排序错误
     
    temp = arr[i];           
    arr[i] = arr[low + 1];  //中值放在最左边
    i = low + 1;            //左右边界缩小1
    j = high - 1;           //边界2个数字插入排序排过，满足左<=中<=右
 
    while (i < j)
    {
        while (temp < arr[j] && i < j)   //从右往左扫描小于目标的值，应该放在左半部分
            j--;
        if (i < j)                        //找到后放在左边
            arr[i++] = arr[j];
        else
            break;
        while (temp > arr[i] && i < j)   //从左往右扫描大于目标的值，要放在右边
            i++;
        if (i< j)
            arr[j--] = arr[i];
        else
            break;
    }
    arr[i] = temp;                       // i = j，正好是分界线，回填目标值
    if ((i - low) > 1) 
        QSpartition(arr, low, i - 1);     //递归左边
    if ((high - i) > 1)
        QSpartition(arr, i + 1, high);     //递归右边
}
 
template <typename T>
void InsertSort(T arr[], int n)   //直接插入排序
{
    int i, j;
    T temp;
 
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (temp < arr[j])            //逐个往前比较，碰到大于目标的，拉过来
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = temp;               //把目标值填入空位
    }
}

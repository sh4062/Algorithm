template <typename T>
void QuickSort(T arr[], int n)   //��������
{
    QSpartition(arr, 0, n - 1);
    InsertSort(arr, n);          //����ò��������������������
}
 
template <typename T>
void QSpartition(T arr[], int low, int high)     //��������ݹ麯��
{
     
//    if (low >= high)     //�в������򣬲���Ҫ���
//        continue;
     
    const int min_insert = 128;
    if (high - low < min_insert)  //����С��һ��������ʱ����ֱ�Ӳ�������
    {
        return;  //����ò��������������������
    }
 
    int i, j;
    T temp;
     
    //����һ����ǰ�к�3�����ݽ��в�������
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
//    if (high - low < 3)   //С�����ò�����������Ͳ���Ҫ�ж���
//        return;           //���ò�������ֻ��2�����ݵ�ʱ���������
     
    temp = arr[i];           
    arr[i] = arr[low + 1];  //��ֵ���������
    i = low + 1;            //���ұ߽���С1
    j = high - 1;           //�߽�2�����ֲ��������Ź���������<=��<=��
 
    while (i < j)
    {
        while (temp < arr[j] && i < j)   //��������ɨ��С��Ŀ���ֵ��Ӧ�÷�����벿��
            j--;
        if (i < j)                        //�ҵ���������
            arr[i++] = arr[j];
        else
            break;
        while (temp > arr[i] && i < j)   //��������ɨ�����Ŀ���ֵ��Ҫ�����ұ�
            i++;
        if (i< j)
            arr[j--] = arr[i];
        else
            break;
    }
    arr[i] = temp;                       // i = j�������Ƿֽ��ߣ�����Ŀ��ֵ
    if ((i - low) > 1) 
        QSpartition(arr, low, i - 1);     //�ݹ����
    if ((high - i) > 1)
        QSpartition(arr, i + 1, high);     //�ݹ��ұ�
}
 
template <typename T>
void InsertSort(T arr[], int n)   //ֱ�Ӳ�������
{
    int i, j;
    T temp;
 
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (temp < arr[j])            //�����ǰ�Ƚϣ���������Ŀ��ģ�������
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = temp;               //��Ŀ��ֵ�����λ
    }
}

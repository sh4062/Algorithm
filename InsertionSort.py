def InsertionSort (A):
 for i in range(1,len(A)):
  key=A[i]
  j=i-1
  while j>=0 and A[j]>key:
      A[j+1]=A[j]
      j-=1

  A[j+1]=key




a=[8,2,4,9,3,6]
InsertionSort(a)
print (a)






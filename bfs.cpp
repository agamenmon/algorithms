/*
* Tìm kiếm theo chiều rộng
*   là thuật toán tìm kiếm trong đồ thị bao gồm 2 thao tác:
*        - Cho trước một đỉnh của đồ thị
*        - Thêm các đỉnh kể với đỉnh vừa cho vào danh sách có thể hướng tới tiêp theo
*    Mục đich;
*        - Tìm kiếm đường đi từ đỉnh gốc cho trước tới một đỉnh đích
*        - Tim kiếm đường đi từ một đỉnh tới tất cả các đỉnh khác
*
*Solutions:
*    1. Chèn đỉnh gốc vào hàng đợi
*    2. Lấy đỉnh đầu tiên trong hàng đợi và quan sát nó
*        - Nếu đỉnh này là đỉnh đích thì dừng qá trình tìm kiếm và trả về kết qả
*        - Nếu không phải là đỉnh thì chèn tất cả các đỉnh kề với đỉnh vừa thâm nhưng 
*            chưa được quan sát trước đó vào hàng đợi
*    3. Nếu hàng đợi là rỗng thì tất cả các đỉnh thì tất cả các đỉnh có thể đến được đều đã được quan sát.
*        dừng việc tìm kiếm và trả về không thấy.
*    4. Nếu hàng đợi không rỗng thì quay lại bước 2.
*
*Ứng dụng:
*    Tím tất cả các đỉnh trong thành phần liên thông
*    Tìm đường đi ngắn nhất giữa hai đỉnh U và V
*    Kiểm tra 1 đồ thị có phải là đồ thị hai phía.
*    Tìm các thành phần liên thông
*/

#include <iostream>
#include <conio.h>

using namespace std;

#define TRUE           1
#define FALSE          0

int InitialValue(int peakNumber)
{
    int arrayValue[peakNumber][peakNumber];
    
    /* input the value on matrix */
    for(int column = 0; column < peakNumber; column++)
    {
        for(int row = 0; row < peakNumber; row++)
        {
            cin >> Array[column][row];
        }
    }
    return arrayValue;
}

/* Breadth first search */
void bfs_function(int value, int N, int notCheckingValue[], int Array[][])
[
    int temper, startQueue, endQueue;

    startQueue = 0;
    endQueue = 0;
    QUEUE[endQueue] = value;
    notCheckingValue[value] = FALSE;

    /* thiet lap hang doi voi dinh dau la i */
    while(startQueue <= endQueue ){
        /* lay dinh u ra khoi hang doi */
        temper = QUEUE[startQueue];
        cout << "Scan Value: " << temper << endl;
        
        /* duyet dinh dau hang doi */
        startQueue++;
        for(int row = 0; row < N; row++)
        {
            if ((Array[value][row] == 1]) && (notCheckingValue[row]))
            {
                endQueue++;
                QUEUE[endQueue] = row;
                notCheckingValue[row] = FALSE;
            }
        }
    }
]

int main(int argc, char ** argv)
{
    int peakNumber = 0;

    /* input the peak Number, max number peak and these value must be not equal 0 */
    while((!peakNumber) &&(!maxNumberPeak))
    {
        cout << "input the total Peak: " << endl;
        cin << peakNumber;
    }
    
    int arraryValue[peakNumber][peakNumber];
    int notCheckingValue[peakNumber];
    int queueValue[peakNumber];

    /* input the other value for the matrix */
    arrayValue = InitialValue(peakNumber);

    /* mark notCheckValue is true for all peak */
    for(int i = 0; i < n; i++)
    {
        notCheckingValue[i] = TRUE;
    }

    /* checking the array with the bfs algorithms */
    for(int count = 0; count <= peakNumber; count++)
    {
        if(notCheckingValue[count])
        {
            bfs_function(count);
        }
    }
    _getch();
}
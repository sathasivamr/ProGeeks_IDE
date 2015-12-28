import java.util.*;		
class shopping
{
	public static void main(String... args)
	{
		Scanner sc = new Scanner(System.in);
      	int t = sc.nextInt();
      	for(int i=0;i<t;i++){
        	int n = sc.nextInt();
          	int sum = 0;
          	int previousIndex = -1;
          	for(int j=0;j<n;j++){
              	int min = 10000;
              	int index = -1;
            	for(int k=0;k<3;k++){ 
                	int temp = sc.nextInt();
                  	if(temp < min && previousIndex != k) {
                      min = temp;
                      index = k;
                    }
                }
              	sum += min;
              	previousIndex = index; 
            }
          	System.out.println(sum);
        }
	}
}
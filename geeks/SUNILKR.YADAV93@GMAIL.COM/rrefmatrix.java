/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *
 * @author Ravi
 */
import java.util.Scanner;
import java.util.ArrayList;


public class rrefmatrix {
    int rows,cols,offset;
    double[][] values;
    boolean finished;
    

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);         
        rrefmatrix test1 = new rrefmatrix(); 
        
        String line=sc.nextLine();
        String[] line_parts = line.split("<>");
        
        test1.rows=line_parts.length;
        test1.offset=-1;
        test1.finished=false;
        
        String[] value_parts = line_parts[0].split(",");
        
        test1.cols=value_parts.length;
        test1.values = new double[test1.rows][test1.cols];
        for(int i=0;i<line_parts.length;i++){
            value_parts=line_parts[i].split(",");
            for(int j=0;j<value_parts.length;j++){
                test1.values[i][j]=Double.parseDouble(value_parts[j]);
            }
        }
        //System.out.println(test1);        
        test1.doEuclid();
        test1.Output();
    }
    @Override
    public String toString(){
        String a="";
        a+="rows="+rows+" cols="+cols+"\n";
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                a+=Double.toString(values[i][j])+" ";
            }
            a+="\n";
        }
        return a;
    }
    
    public void doEuclid(){
        for(int r=0;r<rows && !finished;r++){
            doEuclid(r);
            //System.out.println(this);
        }
        
    }
    
    public void doEuclid(int row){
        int temp_offset=offset,exchange_row=-1;
        double temp;
        for(int j=offset+1;j<cols;j++){
            if (Math.abs(values[row][j])>0.000001){
                temp_offset=j;
                break;
            }
        }
        
        if(temp_offset==offset){
            for(int r=rows-1;r>row && exchange_row==-1;r--){
                for(int c=offset+1;c<cols;c++){
                    if(Math.abs(values[r][c])>0.000001){
                        exchange_row=r;
                        temp_offset=c;
                        break;
                    }
                }
            }
            if(exchange_row==-1){
            offset=cols-1;
            finished=true;
            return ;
            }
            else{
                exchangeRows(row,exchange_row);
                offset=temp_offset-1;
                doEuclid(row);
                return;               
            }
        }
        else{
            exchange_row=-1;
            for (int c=offset+1;c<temp_offset && exchange_row==-1;c++){                
                for(int r=row+1;r<rows;r++){
                    if(Math.abs(values[r][c])>0.000001){
                        exchange_row=r;
                        break;
                    }
                }
                if(exchange_row==-1){
                    continue;
                }
                else{
                    temp_offset =c;
                    exchangeRows(row,exchange_row);
                    break;
                }
                
            }
            double store=values[row][temp_offset],ratio;
            for(int c=0;c<cols;c++){
                values[row][c]=values[row][c]/store;                
            }
            //System.out.println("normalize :"+this);
            for(int r=0;r<rows;r++){
                ratio = values[r][temp_offset];  
                for(int c=0;c<cols;c++){
                    if(r!=row){              
                        values[r][c] = values[r][c]-values[row][c]*ratio;                        
                    }
                }
            }
            offset=temp_offset;
            
                
            
        }
        
    }
    
    public void exchangeRows(int r1,int r2){
        double temp;
        for(int c=0;c<cols;c++){
            temp=values[r1][c];
            values[r1][c]=values[r2][c];
            values[r2][c]=temp;
        }
    }
    
    public void Output(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                System.out.print(Math.round(values[i][j])+" ");
            }
            System.out.print("\n");
        }
    }
}
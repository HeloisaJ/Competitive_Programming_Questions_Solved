class Solution {

    public boolean [][] grafo;

    public int quant(int[][] grid){
        int numero = 1;
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[i].length; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = numero;
                    numero++;
                }
            }
        }
        return numero - 1;
    }

    public void criarGrafo(int[][] grid){
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[i].length; j++){
                if(grid[i][j] != 0){
                    if(i > 0 && grid[i - 1][j] != 0){
                        grafo[grid[i][j] - 1][grid[i - 1][j] - 1] = true;
                        grafo[grid[i - 1][j] - 1][grid[i][j] - 1] = true;
                    }
                    if(i < grid.length - 1 && grid[i + 1][j] != 0){
                        grafo[grid[i][j] - 1][grid[i + 1][j] - 1] = true;
                        grafo[grid[i + 1][j] - 1][grid[i][j] - 1] = true;
                    }
                    if(j > 0 && grid[i][j - 1] != 0){
                        grafo[grid[i][j] - 1][grid[i][j - 1] - 1] = true;
                        grafo[grid[i][j - 1] - 1][grid[i][j] - 1] = true;
                    }
                    if(j < grid[i].length - 1 && grid[i][j + 1] != 0){
                        grafo[grid[i][j] - 1][grid[i][j + 1] - 1] = true;
                        grafo[grid[i][j + 1] - 1][grid[i][j] - 1] = true;
                    }
                }
            }
        }
    }

    public int calculo(){
        int total = 0, contLig;
        for(int i = 0; i < grafo.length; i++){
            contLig = 0;
            for(int j = 0; j < grafo[i].length; j++){
                if(grafo[i][j]){
                    contLig++;
                }
            }
            total += (4 - contLig);
        }
        return total;
    }

    public int islandPerimeter(int [][] grid) { // Island Perimeter
        int quantNos = quant(grid);
        grafo = new boolean[quantNos][quantNos];
        criarGrafo(grid);
        return calculo();
    }
}


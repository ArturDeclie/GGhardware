#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>


using namespace std;

void setcolor(unsigned short color){ //Atribuir cor ao texto
	
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon,color);
}

int mode;

void darkmode(){ //DarkMode
	system("COLOR 0F");
}

void lightmode(){ //LightMode
	system("COLOR F0");
}

void verificar(){ //da cor aos textos de acordo com escolha
	if(mode==1){
		setcolor(15);
	}else if(mode==2){
		setcolor(240);
	}
}

void titulo(){ //da cor aos titulos de acordo com escolha
	if(mode==1){
		setcolor(4);
	}else if(mode==2){
		setcolor(253);
	}
}

void titu(){
	if(mode==1){
		setcolor(6);
	}else if(mode==2){
		setcolor(244);
	}
}

double stob(string texto){ // Função para somar total de vendas
	double num;
	istringstream ds(texto);
	
	if(!(ds >> num)){
		return 0;
	}
	return num;
}

void menu_1(){ // Menu principal
	titulo();
	cout<< "=============> Bem vindo ao sistema GGHardware <============= \n\n";
	verificar();
	cout<< "Escolha a categoria desejada:\n";
	cout<< "1 - Fornecedores\n2 - Parceiros\n3 - Produtos\n4 - Clientes\n5 - Vendas\n6 - Ajuda\n7 - Sobre\n0 - Sair do Sistema\n-> ";
}

void cad_Cliente() { //Cadastra novos clientes
	
	system("cls"); 
	titu();
	cout << "===================> Cadastrar Novos Clientes <================== \n\n";
	 verificar();   
    fstream fin, fout; 

    fin.open("clientes.csv", ios::in); 
    
    vector<string> linhas; 
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { 
	  
	    linhas.clear(); 
	
	    getline(fin, linha); 
	
	    stringstream s(linha); 
	    
	    char virgula = ','; 

	    while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
	    }
	    x = stoi(linhas[0]); 
	}

    fout.open("clientes.csv", ios::out | ios::app); 
    
    int n;
	    
    cout << "Voce deseja cadastrar quantos clientes? ";
	cin >> n;
    cin.sync();
  
    cout << "Informe os dados de " << n << " Clientes:" << "\n\n";
  
    int codigo, idade;
    string nome, telefone, email, cpf;

    codigo = x; 

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "===========> Adicionar Cliente " << codigo << " <============== \n\n";
  		cout << "Informe o nome do cliente: ";
        getline(cin, nome);
        cout << "Informe o telefone do cliente: ";
        getline(cin, telefone);
        cout << "Informe o e-mail do cliente: ";
        getline(cin, email);
        cout << "Informe o idade do cliente: ";
        cin >> idade;
        cin.sync();
        cout << "Informe o cpf do cliente: ";
        getline(cin, cpf);
        cout << "=======================================================> \n\n";
  		system("cls");
        fout << ", " 
			 << codigo << ", " // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
             << nome << ", "
             << telefone << ", "
             << email << ", "
             << idade << ", "
             << cpf
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
	cout<< "Aperte ENTER para voltar. \n\n";
	system("pause");
	system("cls");
}

void buscar_clientes() { // Busca pelos clientes cadastrados a partir do código
	
	system("cls");  
	titu();
	cout << "===================> Pesquisar Clientes <================== \n\n";
	verificar();
    fstream fin; 
    
    fin.open("clientes.csv", ios::in); 

    int linhan1, linhan2, cont = 0; 
    cout << "Digite o codigo do cliente para visualizar seus dados: ";
    cin >> linhan1;
  
    vector<string> linhas; 
    string linha, palavra, temp;
  
    while (fin >> temp) { 
  
        linhas.clear(); 

        getline(fin, linha); 
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
        }
        
        linhan2 = stoi(linhas[0]); 
  
        if (linhan2 == linhan1) { 
  
            cont = 1; 
            titu();
            cout << "==============> Cliente " << linhas[0] << " <================ \n\n";
            verificar();
            cout << "Codigo: " << linhas[0] << "\n";
            cout << "Nome: " << linhas[1] << "\n";
            cout << "Telefone: " << linhas[2] << "\n";
            cout << "E-mail: " << linhas[3] << "\n";
            cout << "Idade: " << linhas[4] << "\n";
            cout << "CPF: " << linhas[5] << "\n";
            titu();
            cout << "======================================================== \n\n";
            verificar();
            cout<<"Para voltar aperte ENTER. \n\n";
            system("pause");
            break;
        }
    }
    if (cont == 0) { 
        cout << "Dados nao encontrados... \n\n";
        cout<<"\nAperte ENTER para buscar novamente. \n\n";
        system("pause");
        buscar_clientes();
	}
	
} 

void listar_clientes() { // Lista todos os clientes cadastrados
	
	system("cls"); 
	
	fstream fin; 
    
    fin.open("clientes.csv", ios::in); 

    vector<string> linhas; 
    string linha, palavra, temp;
    titu();
    cout << "==============> Lista de Clientes Cadastrados <================ \n\n";
  	verificar();
    while (fin >> temp) { 
  
        linhas.clear(); 

        getline(fin, linha); 
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
        }
		
		cout << "==============> Cliente " << linhas[0] << " <================ \n\n";
		verificar();
            cout << "Nome: " << linhas[1] << "\n";
            cout << "Telefone: " << linhas[2] << "\n";
            cout << "E-mail: " << linhas[3] << "\n";
            cout << "Idade: " << linhas[4] << "\n";
            cout << "CPF: " << linhas[5] << "\n";
            titu();
        cout << "======================================================== \n\n";
	
    }
	verificar();
}
  
void list_clientes_h(){ // Lista os clientes na hora do cadastro de vendas
			system("cls");
	fstream fin; 
    
    fin.open("clientes.csv", ios::in); 

    vector<string> linhas; 
    string linha, palavra, temp;
    titu();
    cout << "==============> Lista de Clientes Cadastrados <================ \n\n";
  
    while (fin >> temp){ 
  
        linhas.clear(); 

        getline(fin, linha); 
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
}
		cout << "======================================================== \n\n";
		verificar();
		cout << "Código:  " << linhas[0] << "\n";
        cout << "Nome: " << linhas[1] << "\n";
        titu();
        cout << "======================================================== \n\n";
}
verificar();
}

void atualizar_clientes() { // Atualiza dados de clientes cadastrados
	
	system("cls"); 
	titu();
	cout << "===================> Atualizar dados dos Clientes <================== \n\n";
	verificar();
    fstream fin, fout; 

    fin.open("clientes.csv", ios::in); 

    fout.open("attclientes.csv", ios::out); 
  
    int linhan1, linhan2, indice, sub, cont = 0; 
    string linha, palavra, novo, temp;
    vector<string> linhas;

    cout << "Digite o codigo do cliente que deseja atualizar os dados: ";
    cin >> linhan1;
    cin.sync();
	titu();
    cout << "==========> Alterar dados do cliente " << linhan1 << " <=========== \n\n";
    verificar();
    cout << "Para alterar o nome, Digite 1. \n";
    cout << "Para alterar o telefone, Digite 2. \n";
    cout << "Para alterar o e-mail, Digite 3. \n";
    cout << "Para alterar a idade, Digite 4. \n";
    cout << "Para alterar o cpf, Digite 5. \n\n";
    cout << "=> ";
    cin >> sub;
  	cin.sync();
  	
  	switch(sub) { 
  		case 1:
  		    cout << "==============> Alterar nome do cliente <================ \n\n";
  			indice = 1;
  			break;
  		case 2:
  			cout << "==============> Alterar telefone do cliente <================ \n\n";
  			indice = 2;
  			break;
  		case 3:
  			cout << "==============> Alterar e-mail do cliente <================ \n\n";
  			indice = 3;
  			break;
  		case 4:
  			cout << "==============> Alterar idade do cliente <================ \n\n";
  			indice = 4;
  			break;
  		case 5:
  			cout << "==============> Alterar CPF do cliente <================ \n\n";
  			indice = 5;
  			break;
  		default:
	        cout << "Opçao Invalida!! \n";
	        atualizar_clientes();
			break;  			
	  }

    cout << "Informe o novo dado: "; 
    getline(cin, novo);

    while (fin >> temp) { 
  
        linhas.clear(); 
  
        getline(fin, linha); 
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        linhan2 = stoi(linhas[0]); 
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert; 

            convert << novo; 

            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    if (cont == 1) {
        cout << "Dados atualizados com Sucesso!! \n";
	} else if (cont == 0) { 
    	cout << "Dados nao encontrados!! Nao foi Possivel atualizar dados! \n\n";
    	atualizar_clientes(); 
	}

    fin.close(); 
    fout.close(); 

    remove("clientes.csv"); 
    rename("attclientes.csv", "clientes.csv"); 
} 

void excluir_clientes() { // Exclui clientes cadastrados
	
	system("cls"); 
	titu();
	cout << "===================> Excluir dados de Clientes <================== \n\n";
	verificar();
    fstream fin, fout; 
    				  

    fin.open("clientes.csv", ios::in); 

    fout.open("attclientes.csv", ios::out); 
  
    int linhan1, linhan2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas; 

	cout << "Digite o codigo do cliente que deseja excluir os dados: ";
    cin >> linhan1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha);  
  
  		char virgula = ','; 
  		
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        int row_size = linhas.size(); 
        linhan2 = stoi(linhas[0]); 

        if (linhan2 != linhan1) { 
        	
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof()) 
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close(); 
    fout.close();

    remove("clientes.csv");
    rename("attclientes.csv", "clientes.csv"); 
    
}

void buscar_prod() { // Busca por produtos cadastrados a partir do codigo
	
	system("cls");  
	titu();
	cout << "-----------------------> Pesquisar Produtos <---------------------------\n\n";
	verificar();
    fstream fin;
    			
    
    fin.open("produtos.csv", ios::in); 

    int linhan1, linhan2, cont = 0; 
    cout << "Digite o codigo do produto para visualizar seus dados: ";
    cin >> linhan1;
  
    vector<string> linhas; 
    string linha, palavra, temp;
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha);
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
        }
        
        linhan2 = stoi(linhas[0]); 
  
        if (linhan2 == linhan1) { 
  
            cont = 1; 
            titu();
            cout << "==============> Produto " << linhas[0] << " <================ \n\n";
            verificar();
            cout << "Codigo: " << linhas[0] << "\n";
            cout << "Nome: " << linhas[1] << "\n";
            cout << "Descrição: " << linhas[2] << "\n";
            cout << "Preço" << linhas[3] << "\n";
            cout << "Fornecedor" << linhas[4] << "\n";
            cout << "Parceiro" << linhas[5] << "\n";
            titu();
            cout << "======================================================== \n\n";
            break;
        }
    }
    verificar();
    if (cont == 0) { 
        cout << "Dados nao encontrados... \n\n";
        cout<<"\nAperte ENTER para buscar novamente. \n\n";
        system("pause");
        buscar_prod(); 
	}
} 

void listar_prod() { // Lista todos os produtos cadastrados
	system("cls");	
	fstream fin; 
    
    fin.open("produtos.csv", ios::in); 

    vector<string> linhas; 
    string linha, palavra, temp;
    titu();
    cout << "==============> Lista de Produtos Cadastrados <================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear(); 

        getline(fin, linha); 
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
        }

		cout << "==============> Produto " << linhas[0] << " <================ \n\n";
			verificar();
            cout << "Nome: " << linhas[1] << "\n";
            cout << "Descrição: " << linhas[2] << "\n";
            cout << "Preço: " << linhas[3] << "\n";
            cout << "Fornecedor: " << linhas[4] << "\n";
            cout << "Parceiro: " << linhas[5] << "\n";
            titu();
        cout << "======================================================== \n\n";

    }
verificar();
}
  
void atualizar_prod() { // atualiza produtos cadastrados
	
	system("cls"); 
	titu();
	cout << "===================> Atualizar dados dos Produtos <================== \n\n";
	verificar();
    fstream fin, fout; 

    fin.open("produtos.csv", ios::in); 

    fout.open("attprodutos.csv", ios::out); 
  
    int linhan1, linhan2, indice, sub, cont = 0; 
    string linha, palavra, novo, temp;
    vector<string> linhas; 

    cout << "Digite o codigo do produto que deseja atualizar os dados: ";
    cin >> linhan1;
    cin.sync();
	titu();
    cout << "==========> Alterar dados do produto " << linhan1 << " <=========== \n\n";
    verificar();
    cout << "Para alterar o nome, Digite 1. \n";
    cout << "Para alterar a descrição, Digite 2. \n";
    cout << "Para alterar o preço, Digite 3. \n";
    cout << "Para alterar o fornecedor, Digite 4. \n";
    cout << "Para alterar o parceiro, Digite 5. \n";
    cout << "=> ";
    cin >> sub;
  	cin.sync();
  	
  	switch(sub) { 
  		case 1:
  		    cout << "==============> Alterar nome do produto <================ \n\n";
  			indice = 1;
  			break;
  		case 2:
  			cout << "==============> Alterar descrição do produto <================ \n\n";
  			indice = 2;
  			break;
  		case 3:
  			cout << "==============> Alterar preco do produto <================ \n\n";
  			indice = 3;
  			break;
  		case 4:
  			cout << "==============> Alterar fornecedor <================ \n\n";
  			indice = 4;
  			break;
  		case 5:
  			cout << "==============> Alterar parceiro <================ \n\n";
  			indice = 5;
  			break;
  		default:
	        cout << "Opçao Invalida!! \n";
	        atualizar_prod();
			break;  			
	  }

    cout << "Informe o novo dado: "; 
    getline(cin, novo);

    while (fin >> temp) { 
  
        linhas.clear(); 
  
        getline(fin, linha); 
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        linhan2 = stoi(linhas[0]);
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert; 

            convert << novo; 

            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    if (cont == 1) { 
        cout << "Dados atualizados com Sucesso!! \n";
	} else if (cont == 0) { 
    	cout << "Dados nao encontrados!! Nao foi Possivel atualizar dados! \n\n";
    	atualizar_prod(); 
	}

    fin.close(); 
    fout.close(); 

    remove("produtos.csv"); 
    rename("attprodutos.csv", "produtos.csv"); 
} 

void excluir_prod() { // Exclui produto cadastrado
	
	system("cls"); 
	titu();
	cout << "===================> Excluir Produto <================== \n\n";
	verificar();
    fstream fin, fout; 

    fin.open("produtos.csv", ios::in); 

    fout.open("attprodutos.csv", ios::out); 
  
    int linhan1, linhan2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas; 

	cout << "Digite o codigo do produto que deseja excluir os dados: ";
    cin >> linhan1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha);  
  
  		char virgula = ','; 
  		
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        int row_size = linhas.size(); 
        linhan2 = stoi(linhas[0]); 

        if (linhan2 != linhan1) { 
        	
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof()) 
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close(); 
    fout.close(); 

    remove("produtos.csv"); 
    rename("attprodutos.csv", "produtos.csv");
    
	
} 

void criar_fornecedor() { // Cadastra novos fornecedores
	
	system("cls"); 
	titu();
	cout << "===================> Cadastrar Novos Fornecedores <================== \n\n";
	verificar();    
    fstream fin, fout; 

    fin.open("fornecedores.csv", ios::in); 
    
    vector<string> linhas; 
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { 
	  
	    linhas.clear(); 
	
	    getline(fin, linha); 
	
	    stringstream s(linha);
	    
	    char virgula = ','; 

	    while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
	    }
	    x = stoi(linhas[0]); 
	}

    fout.open("fornecedores.csv", ios::out | ios::app); 
    
    int n;
	    
    cout << "Voce deseja cadastrar quantos fornecedores? ";
	cin >> n;
    cin.sync();
  
    cout << "Informe os dados de " << n << " Fornecedores:" << "\n\n";
  
    int codigo;
    string nome, contato, cnpj;

    codigo = x; 

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
    	titu();
  		cout << "===========> Adicionar Fornecedor " << codigo << " <============== \n\n";
  		verificar();
  		cout << "Informe o nome do fornecedor: ";
        getline(cin, nome);
        cout << "Informe o contato do fornecedor: ";
        getline(cin, contato);
        cout << "Informe o CNPJ do fornecedor: ";
        getline(cin, cnpj);
        cin.sync();
        titu();
        cout << "=======================================================> \n\n";
        verificar();
  
        fout << ", " 
			 << codigo << ", " 
             << nome << ", "
             << contato << ", "
             << cnpj << ", "
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
	cout<< "Aperte ENTER para voltar. \n\n";
	system("pause");
}

void buscar_fornecedor() { // Busca fornecedor cadastrado pelo codigo
	
	system("cls"); 
	titu();
	cout << "===================> Pesquisar Fornecedor <================== \n\n";
	verificar();
    fstream fin; 
    
    fin.open("fornecedores.csv", ios::in); 

    int linhan1, linhan2, cont = 0; 
    cout << "Digite o codigo do cliente para visualizar seus dados: ";
    cin >> linhan1;
  
    vector<string> linhas; 
    string linha, palavra, temp;
  
    while (fin >> temp) { 
  
        linhas.clear(); 

        getline(fin, linha); 
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
        }
        
        linhan2 = stoi(linhas[0]); 
  
        if (linhan2 == linhan1) { 
  
            cont = 1; 
            titu();
            cout << "==============> Cliente " << linhas[0] << " <================ \n\n";
            verificar();
            cout << "Codigo: " << linhas[0] << "\n";
            cout << "Nome: " << linhas[1] << "\n";
            cout << "Contato: " << linhas[2] << "\n";
            cout << "CNPJ: " << linhas[3] << "\n";
            titu();
            cout << "======================================================== \n\n";
            verificar();
            break;
        }
    }
    if (cont == 0) { 
        cout << "Dados nao encontrados... \n\n";
        cout<<"\nAperte ENTER para buscar novamente. \n\n";
        system("pause");
        buscar_fornecedor(); 
	}
	
} 

void listar_fornecedor() { // Lista todos os fornecedores cadastrados
	
	system("cls"); 
		
	fstream fin; 
    
    fin.open("fornecedores.csv", ios::in); 

    vector<string> linhas; 
    string linha, palavra, temp;
    titu();
    cout << "==============> Lista de Fornecedores Cadastrados <================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear(); 

        getline(fin, linha); 
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
        }

		cout << "==============> Fornecedor " << linhas[0] << " <================ \n\n";
			verificar();
            cout << "Nome: " << linhas[1] << "\n";
            cout << "Contato: " << linhas[2] << "\n";
            cout << "CNPJ: " << linhas[3] << "\n";
            titu();
        cout << "======================================================== \n\n";

    }
	verificar();
}
  
void atualizar_fornecedor() { //Atualiza dados de fornecedores cadastrados
	
	system("cls"); 
	titu();
	cout << "===================> Atualizar dados dos Fornecedores <================== \n\n";
	verificar();
    fstream fin, fout; 
    				  

    fin.open("fornecedores.csv", ios::in);

    fout.open("attfornecedores.csv", ios::out); 
  
    int linhan1, linhan2, indice, sub, cont = 0; 
    string linha, palavra, novo, temp;
    vector<string> linhas; 

    cout << "Digite o codigo do fornecedor que deseja atualizar os dados: ";
    cin >> linhan1;
    cin.sync();
	titu();
    cout << "==========> Alterar dados do Fornecedor " << linhan1 << " <=========== \n\n";
    verificar();
    cout << "Para alterar o nome, Digite 1. \n";
    cout << "Para alterar o contato, Digite 2. \n";
    cout << "Para alterar a CNPJ, Digite 3. \n";
    cout << "=> ";
    cin >> sub;
  	cin.sync();
  	
  	switch(sub) { 
  		case 1:
  		    cout << "==============> Alterar nome do Fornecedor <================ \n\n";
  			indice = 1;
  			break;
  		case 2:
  			cout << "==============> Alterar contato do Fornecedor <================ \n\n";
  			indice = 2;
  			break;
  		case 3:
  			cout << "==============> Alterar o CNPJ <================ \n\n";
  			indice = 3;
  			break;
  		default:
	        cout << "Opçao Invalida!! \n";
	        atualizar_fornecedor();
			break;  			
	  }

    cout << "Informe o novo dado: "; 
    getline(cin, novo);

    while (fin >> temp) { 
  
        linhas.clear(); 
  
        getline(fin, linha); 
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        linhan2 = stoi(linhas[0]); 
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert; 

            convert << novo; 

            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    if (cont == 1) { 
        cout << "\n\nDados atualizados com Sucesso!! \n";
	} else if (cont == 0) { 
    	cout << "Dados nao encontrados!! Nao foi Possivel atualizar dados! \n\n";
    	atualizar_fornecedor(); 
	}

    fin.close(); 
    fout.close(); 

    remove("fornecedores.csv"); 
    rename("attfornecedores.csv", "fornecedores.csv"); 
} 

void excluir_fornecedor() { // Exclui fornecedores cadastrados
	
	system("cls");
	titu();
	cout << "===================> Excluir dados de Fornecedores <================== \n\n";
	verificar();
    fstream fin, fout; 

    fin.open("fornecedores.csv", ios::in); 

    fout.open("attfornecedores.csv", ios::out); 
  
    int linhan1, linhan2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas; 

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linhan1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha);  
  
  		char virgula = ','; 
  		
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        int row_size = linhas.size(); 
        linhan2 = stoi(linhas[0]); 

        if (linhan2 != linhan1) { 
        	
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof()) 
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close(); 
    fout.close(); 

    remove("fornecedores.csv"); 
    rename("attfornecedores.csv", "fornecedores.csv");
    
	 
	
}

void cad_parceiros() { // Cadastra novos Parceiros
	
	system("cls"); 
	titu();
	cout << "===================> Cadastrar Novos Parceiros <================== \n\n";
	verificar();   
    fstream fin, fout; 

    fin.open("parceiros.csv", ios::in); 
    
    vector<string> linhas; 
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { 
	  
	    linhas.clear(); 
	
	    getline(fin, linha); 
	
	    stringstream s(linha); 
	    
	    char virgula = ','; 

	    while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
	    }
	    x = stoi(linhas[0]); 
	}

    fout.open("parceiros.csv", ios::out | ios::app); 
    
    int n;
	    
    cout << "Voce deseja cadastrar quantos parceiros? ";
	cin >> n;
    cin.sync();
  
    cout << "Informe os dados de " << n << " Parceiros:" << "\n\n";
  
    int codigo;
    string nome, contato, CNPJ;

    codigo = x; 

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
    	titu();
  		cout << "===========> Adicionar Parceiro " << codigo << " <============== \n\n";
  		verificar();
  		cout << "Informe o nome do parceiro: ";
        getline(cin, nome);
        cout << "Informe o contato do parceiro: ";
        getline(cin, contato);
        cin.sync();
        cout << "Informe o CNPJ do parceiro: ";
        getline(cin, CNPJ);
        titu();
        cout << "=======================================================> \n\n";
  		verificar();
        fout << ", " 
			 << codigo << ", " // ,codigo[0] , nome[1] , contato[2] , cnpj[3]
             << nome << ", "
             << contato << ", "
             << CNPJ << ", "
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
	cout<< "Aperte ENTER para voltar. \n\n";
	system("pause");
}

void buscar_parceiros() { //Busca por um parceiro cadastrado utilizando seu codigo
	
	system("cls");  
	titu();
	cout << "===================> Pesquisar Parceiros <================== \n\n";
	verificar();
    fstream fin; 
    
    fin.open("parceiros.csv", ios::in); 

    int linhan1, linhan2, cont = 0; 
    cout << "Digite o codigo do parceiro para visualizar seus dados: ";
    cin >> linhan1;
  
    vector<string> linhas; 
    string linha, palavra, temp;
  
    while (fin >> temp) { 
  
        linhas.clear(); 

        getline(fin, linha); 
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
        }
        
        linhan2 = stoi(linhas[0]); 
  
        if (linhan2 == linhan1) { 
  
            cont = 1; 
            titu();
            cout << "==============> Parceiro " << linhas[0] << " <================ \n\n";
            verificar();
            cout << "Codigo: " << linhas[0] << "\n";
            cout << "Nome: " << linhas[1] << "\n";
            cout << "Contato: " << linhas[2] << "\n";
            cout << "CNPJ: " << linhas[3] << "\n";
            titu();
            cout << "======================================================== \n\n";
            verificar();
            break;
        }
    }
    if (cont == 0) { 
        cout << "Dados nao encontrados... \n\n";
        cout<<"\nAperte ENTER para buscar novamente. \n\n";
        system("pause");
        buscar_parceiros(); 
	}
} 

void listar_parceiros() { //Lista todos os parceiros cadastrados
	
	system("cls"); 
	
	fstream fin; 
    
    fin.open("parceiros.csv", ios::in); 

    vector<string> linhas; 
    string linha, palavra, temp;
    
    titu();
    cout << "==============> Lista de Parceiros <================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear(); 

        getline(fin, linha); 
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
        }
		titu();
		cout << "==============> Parceiro " << linhas[0] << " <================ \n\n";
			verificar();
            cout << "Nome: " << linhas[1] << "\n";
            cout << "Contato: " << linhas[2] << "\n";
            cout << "CNPJ: " << linhas[3] << "\n";
            titu();
        cout << "======================================================== \n\n";

    }
	verificar();
}
  
void atualizar_parceiros() { // Atualiza Dados de parceiros cadastrados
	
	system("cls"); 
	titu();
	cout << "===================> Atualizar dados dos Parceiros <================== \n\n";
	verificar();
    fstream fin, fout; 

    fin.open("parceiros.csv", ios::in); 

    fout.open("attparceiros.csv", ios::out); 
  
    int linhan1, linhan2, indice, sub, cont = 0; 
    string linha, palavra, novo, temp;
    vector<string> linhas; 

    cout << "Digite o codigo do parceiro que deseja atualizar os dados: ";
    cin >> linhan1;
    cin.sync();
	titu();
    cout << "==========> Alterar dados do parceiro " << linhan1 << " <=========== \n\n";
    verificar();
    cout << "Para alterar o nome, Digite 1. \n";
    cout << "Para alterar o contato, Digite 2. \n";
    cout << "Para alterar o CNPJ, Digite 3. \n";
    cout << "=> ";
    cin >> sub;
  	cin.sync();
  	
  	switch(sub) { 
  		case 1:
  		    cout << "==============> Alterar nome do Parceiro <================ \n\n";
  			indice = 1;
  			break;
  		case 2:
  			cout << "==============> Alterar contato do Parceiro <================ \n\n";
  			indice = 2;
  			break;
  		case 3:
  			cout << "==============> Alterar CNPJ do Parceiro <================ \n\n";
  			indice = 3;
  			break;
  		default:
	        cout << "Opçao Invalida!! \n";
	        atualizar_parceiros();
			break;  			
	  }

    cout << "Informe o novo dado: "; 
    getline(cin, novo);

    while (fin >> temp) { 
  
        linhas.clear(); 
  
        getline(fin, linha); 
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        linhan2 = stoi(linhas[0]); 
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert; 

            convert << novo; 

            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    if (cont == 1) { 
        cout << "Dados atualizados com Sucesso!! \n";
	} else if (cont == 0) { 
    	cout << "Dados nao encontrados!! Nao foi Possivel atualizar dados! \n\n";
    	atualizar_parceiros(); 
	}

    fin.close(); 
    fout.close(); 

    remove("parceiros.csv"); 
    rename("attparceiros.csv", "parceiros.csv"); 
} 

void excluir_parceiros() { // Excluir Parceiros cadastrados
	
	system("cls"); 
	titu();
	cout << "===================> Excluir dados de Parceiros <================== \n\n";
	verificar();
    fstream fin, fout; 

    fin.open("parceiros.csv", ios::in); 

    fout.open("attparceiros.csv", ios::out); 
  
    int linhan1, linhan2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas; 

	cout << "Digite o codigo do parceiro que deseja excluir os dados: ";
    cin >> linhan1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha);  
  
  		char virgula = ','; 
  		
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        int row_size = linhas.size(); 
        linhan2 = stoi(linhas[0]); 

        if (linhan2 != linhan1) { 
        	
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof()) 
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close(); 
    fout.close(); 

    remove("parceiros.csv"); 
    rename("attparceiros.csv", "parceiros.csv"); 
    
	
}

void cad_venda(){ // Cadastrar novas vendas
	system("cls"); 
	titu();
	cout << "===================> Cadastrar Novas Vendas <================== \n\n";
	verificar();    
    fstream fin, fout; 

    fin.open("vendas.csv", ios::in); 
    
    vector<string> linhas; 
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { 
	  
	    linhas.clear(); 
	
	    getline(fin, linha); 
	
	    stringstream s(linha); 
	    
	    char virgula = ','; 

	    while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
	    }
	    x = stoi(linhas[0]); 
	}

    fout.open("vendas.csv", ios::out | ios::app); 
    
    int n;
	    
    cout << "Voce deseja cadastrar quantos clientes? ";
	cin >> n;
    cin.sync();
  
    
  
    int codigo, codprod,cod;
    string nome, prod,preco;
    
	
    codigo = x; 

    for (int i = 0; i < n; i++) {
    	titu();
		cout << "Informe os dados da " << n << " Venda:" << "\n\n";
    	codigo++;
  		cout << "===========> Adicionar Venda " << codigo << " <============== \n\n";
  		verificar();
  		list_clientes_h();
  		cout << "\n\nInforme o código do cliente: ";
        cin >> cod;
        cin.sync();
        cout << "Informe o nome do cliente: ";
        getline(cin, nome);
		listar_prod();
		cout << "Informe o código do produto: ";
		cin>>codprod;
		cin.sync();
		cout << "Informe o nome do produto: ";
		getline(cin,prod);
		cout<<"Informe o preço do produto: ";
		getline(cin,preco);
		system("cls");
        fout << ", " 
        	 << codigo<< ", "// ,codigo[0] , cod[1] , nome[2] , codprod[3] , prod[4] , preco[5] 
			 << cod << ", " 
             << nome << ", "
             << codprod << ", "
             << prod << ", "
             << preco << ", "
             << "\n";
        
    }
	cout << "Dados Gravados com Sucesso! \n";
	cout<< "Aperte ENTER para voltar. \n\n";
	system("pause");
}

void buscar_venda(){ // Buscar dados de Vendas
		system("cls");  
	titu();
	cout << "===================> Pesquisar Vendas <================== \n\n";
	verificar();
    fstream fin; 
    
    fin.open("vendas.csv", ios::in); 

    int linhan1, linhan2, cont = 0; 
    cout << "Digite o codigo do cliente para visualizar os dados de venda: ";
    cin >> linhan1;
  
    vector<string> linhas; 
    string linha, palavra, temp;
    double total=0;
  
    while (fin >> temp) { 
  
        linhas.clear(); 

        getline(fin, linha); 
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }
        
        linhan2 = stoi(linhas[1]); 
  
        if (linhan2 == linhan1) { 
  
            cont = 1; 
            titu();
            cout << "==============> Venda " << linhas[0] << " <================ \n\n";
            verificar();
            cout << "Codigo Cliente: " << linhas[1] << "\n";
            cout << "Nome Cliente: " << linhas[2] << "\n";
            cout << "Código Produto: " << linhas[3] << "\n";
            cout << "Nome Produto: " << linhas[4] << "\n";
            cout << "Preço: R$" << linhas[5] << "\n";
            titu();
            cout << "======================================================== \n\n";
            verificar();
            total += stob(linhas[5]);
        }
        
    }
    titulo();
    cout<< "Valor Total de Vendas desse Cliente é de: R$"<< total<<endl;
    verificar();
    
    if (cont == 0) { 
        cout << "Dados nao encontrados... \n\n";
        cout<<"\nAperte ENTER para buscar novamente. \n\n";
        system("pause");
        buscar_venda();
	}
}

void listar_venda(){ // Lista Todas as Vendas Cadastradas
		system("cls"); 
	
	fstream fin; 
    
    fin.open("vendas.csv", ios::in); 

    vector<string> linhas; 
    string linha, palavra, temp;
    double total=0;
    titu();
    cout << "==============> Lista de Vendas Cadastradas <================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear(); 

        getline(fin, linha); 
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
        }
		titu();
		cout << "==============> Venda " << linhas[0] << " <================ \n\n";
			verificar();
            cout << "Código do Cliente: " << linhas[1] << "\n";
            cout << "Nome do Cliente: " << linhas[2] << "\n";
            cout << "Código do Produto: " << linhas[3] << "\n";
            cout << "Nome do Produto: " << linhas[4] << "\n";
            cout << "Preço: " << linhas[5] << "\n";
            titu();
        cout << "======================================================== \n\n";
		verificar();
	total += stob(linhas[5]);
    }
	titulo();
	cout<< "Valor Total de Vendas: R$"<< total<<endl;
	verificar();
}

void atualizar_venda(){ // Atualizar Vendas
	system("cls"); 
	titu();
	cout << "===================> Atualizar dados da Venda <================== \n\n";
	verificar();
    fstream fin, fout; 

    fin.open("vendas.csv", ios::in); 

    fout.open("attvendas.csv", ios::out); 
  
    int linhan1, linhan2, indice, sub, cont = 0; 
    string linha, palavra, novo, temp;
    vector<string> linhas; 

    cout << "Digite o codigo da venda que deseja atualizar os dados: ";
    cin >> linhan1;
    cin.sync();
	titu();
    cout << "==========> Alterar dados do venda " << linhan1 << " <=========== \n\n";
    verificar();
    cout << "Para alterar o código do cliente, Digite 1. \n";
    cout << "Para alterar o nome do cliente, Digite 2. \n";
    cout << "Para alterar o código do produto, Digite 3. \n";
    cout << "Para alterar o produto, Digite 4. \n";
    cout << "Para alterar o preço, Digite 5. \n\n";
    cout << "=> ";
    cin >> sub;
  	cin.sync();
  	
  	switch(sub) { 
  		case 1:
  		    cout << "==============> Alterar código do cliente <================ \n\n";
  			indice = 1;
  			break;
  		case 2:
  			cout << "==============> Alterar nome do cliente <================ \n\n";
  			indice = 2;
  			break;
  		case 3:
  			cout << "==============> Alterar código do produto <================ \n\n";
  			indice = 3;
  			break;
  		case 4:
  			cout << "==============> Alterar o produto <================ \n\n";
  			indice = 4;
  			break;
  		case 5:
  			cout << "==============> Alterar o preço <================ \n\n";
  			indice = 5;
  			break;
  		default:
	        cout << "Opçao Invalida!! \n";
	        atualizar_clientes();
			break;  			
	  }

    cout << "Informe o novo dado: "; 
    getline(cin, novo);

    while (fin >> temp) { 
  
        linhas.clear(); 
  
        getline(fin, linha); 
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        linhan2 = stoi(linhas[0]); 
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert; 

            convert << novo; 

            linhas[indice] = convert.str();
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    if (cont == 1) { 
        cout << "Dados atualizados com Sucesso!! \n";
	} else if (cont == 0) { 
    	cout << "Dados nao encontrados!! Nao foi Possivel atualizar dados! \n\n";
    	atualizar_clientes();  
	}

    fin.close(); 
    fout.close(); 

    remove("vendas.csv"); 
    rename("attvendas.csv", "vendas.csv"); 
}

void excluir_venda(){ // Excluir Vendas
		system("cls"); 
	titu();
	cout << "===================> Excluir dados de Vendas <================== \n\n";
	verificar();
    fstream fin, fout; 

    fin.open("vendas.csv", ios::in); 

    fout.open("attvendas.csv", ios::out); 
  
    int linhan1, linhan2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas; 

	cout << "Digite o codigo da venda que deseja excluir os dados: ";
    cin >> linhan1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha);  
  
  		char virgula = ','; 
  		
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        int row_size = linhas.size(); 
        linhan2 = stoi(linhas[0]);

        if (linhan2 != linhan1) { 
        	
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof()) 
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close(); 
    fout.close(); 

    remove("vendas.csv"); 
    rename("attvendas.csv", "vendas.csv"); 
}

void cad_prod() {//Cadastro de Produtos
	
	system("cls"); 
	titu();
	cout << "===================> Cadastrar Produtos <================== \n\n";
	verificar();    
    fstream fin, fout; 

    fin.open("produtos.csv", ios::in);
    
    vector<string> linhas; 
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { 
	  
	    linhas.clear(); 
	
	    getline(fin, linha); 
	
	    stringstream s(linha); 
	    
	    char virgula = ','; 

	    while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
	    }
	    x = stoi(linhas[0]); 
	}

    fout.open("produtos.csv", ios::out | ios::app); 
    
    int n;
	    
    cout << "Voce deseja cadastrar quantos produtos? ";
	cin >> n;
    cin.sync();
  
    cout << "Informe os dados do " << n << " Produto:" << "\n\n";
  
    int codigo;
    float preco;
    string nome, descricao, fornecedor, parceiro;

    codigo = x; 

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
    	titu();
  		cout << "~~~~~~~~~~~~~~> Adicionar Produto " << codigo << " <~~~~~~~~~~~~~~ \n\n";
  		verificar();
  		cout << "Informe a nome do produto: ";
        getline(cin, nome);
        cout << "Informe a descrição do produto: ";
        getline(cin, descricao);
        cout <<"Informe o preço do produto: ";
        cin >> preco;
        cin.sync();
        system("cls");
        listar_fornecedor();
        cout<<"\nInforme o nome do fornecedor: ";
        getline(cin,fornecedor);
        system("cls");
        listar_parceiros();
        cout<<"\nInforme o nome do parceiro em que o produto está anunciado: ";
        getline(cin,parceiro);
        cout<<"\n";
        system("cls");
  
        fout << ", "  
			 << codigo << ", " // ,codigo[0] , nome[1] , descrição[2] , preco[3] , fornecedor[4] , parceiro[5]
             << nome << ", "
             << descricao << ", "
             << preco << ", "
             << fornecedor << ", "
             << parceiro << ", "
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
	cout<< "Aperte ENTER para voltar. \n\n";
	system("pause");
	system("cls");
}

int main(int argc, char** argv) { // Inicialização do programa
	
	setlocale(LC_ALL, "Portuguese");
	
	int op,op1,start = 2;
	string menu,login,senha;
	
	system("COLOR DF");
	cout<<"Escolha a opção desejada: \n1 - Darkmode\n2 - Lightmode\n-> ";
	cin>>mode;
	cin.sync();
	if(mode==1){
		darkmode();
	}else if(mode==2){
		lightmode();
	}else{
		cout<<"Opção inválida.";
	}
	system("cls");
	while(start==2){
	titulo();	
	cout<<"=========> LOGIN GGHARDWARE <========= \n\n"; // Login do Sistema
	cout<<"Login: ";
	getline(cin,login);
	cout<<"Senha: ";
	getline(cin,senha);
	if((login=="admin")&&(senha=="admin")){
	system("cls");
	start=1;
	while(start == 1) {
		verificar();
		menu_1();// Menu Principal
		cin>>op;
		cin.sync();
		system("cls");
			switch (op){
				case 1: //Menu Fornecedores
					system("cls");
					menu="menu1";
					while(menu=="menu1"){
					titulo();
					cout<<"=========> Menu Fornecedores <========= \n\n";
					verificar();
					cout << "Digite uma opção: \n1 - Cadastrar Fornecedor\n2 - Buscar Fornecedor\n3 - Listar Fornecedores\n4 - Atualizar Informações\n5 - Excluir Cadastro\n0 - Voltar ao Menu Principal\n->";
					cin >> op1;
					switch(op1){
							
							case 1:{
								criar_fornecedor();
								system("cls");
								break;
							}
							case 2:{
								buscar_fornecedor();
								cout<<"Aperte ENTER para voltar.\n";
								system("pause");
								system("cls");
								break;
							}
							case 3:{
								listar_fornecedor();
								cout<<"Aperte ENTER para voltar.\n";
								system("pause");
								system("cls");
								break;
							}
							case 4:{
								atualizar_fornecedor();
								cout<<"Aperte ENTER para voltar.\n";
								system("pause");
								system("cls");
								break;
							}
							case 5:{
								excluir_fornecedor();
								cout<<"Aperte ENTER para voltar.\n";
								system("pause");
								system("cls");
								break;
							}
							case 0:{
								system("cls");
								menu="0";
								break;
							}
							default:{
								system("cls");
								cout << "Opçao invalida! \n";
								break;
							}
					}
				}
				
				
				
					break;
				case 2: //Menu de Parceiros
				system("cls");
					menu="menu2";
					while(menu=="menu2"){
						titulo();
					cout<<"=========> Menu Parceiros <========= \n\n";
					verificar();
					cout << "Digite uma opção: \n1 - Cadastrar Parceiro\n2 - Buscar Parceiro\n3 - Listar Parceiros\n4 - Atualizar Informações\n5 - Excluir Cadastro\n0 - Voltar ao Menu Principal\n->";
					cin >> op1;
					switch(op1){
						case 1:{
							cad_parceiros();
							system("cls");
							break;
						}
						case 2:{
							buscar_parceiros();
							cout<<"Aperte ENTER para voltar.\n";
							system("pause");
							system("cls");
							break;
						}
						case 3:{
							listar_parceiros();
							cout<<"Aperte ENTER para voltar.\n";
							system("pause");
							system("cls");
							break;
						}
						case 4:{
							atualizar_parceiros();
							cout<<"Aperte ENTER para voltar.\n";
							system("pause");
							system("cls");
							break;
						}
						case 5:{
							excluir_parceiros();
							cout<<"Aperte ENTER para voltar.\n";
							system("pause");
							system("cls");
							break;
						}
						case 0:{
							system("cls");
							menu="0";
							break;
						}
						default:{
							system("cls");
							cout << "Opçao invalida! \n";
							break;
						}
						
					}
				}
				
				
					
					break;
					
				case 3: // Menu de Produtos
					system("cls");
					menu="menu3";
					while(menu=="menu3"){	
					titulo();
					cout<<"=========> Menu Produtos <========= \n\n";
					verificar();
					cout << "Digite uma opção: \n1 - Cadastrar Produto\n2 - Buscar Produto\n3 - Listar Produtos\n4 - Atualizar Informações\n5 - Excluir Cadastro\n0 - Voltar ao Menu Principal\n->";
					cin >> op1;
					
						switch(op1){
							
							case 1:{
								cad_prod();
								system("cls");
								break;
							}
							case 2:{
								buscar_prod();
								cout<<"Aperte ENTER para voltar.\n";
								system("pause");
								system("cls");
								break;
							}
							case 3:{
								listar_prod();
								cout<<"Aperte ENTER para voltar.\n";
								system("pause");
								system("cls");
								break;
							}
							case 4:{
								atualizar_prod();
								cout<<"Aperte ENTER para voltar.\n";
								system("pause");
								system("cls");
								break;
							}
							case 5:{
								excluir_prod();
								cout<<"Aperte ENTER para voltar.\n";
								system("pause");
								system("cls");
								break;
							}
							case 0:{
								system("cls");
								menu="0";
								break;
							}
							default:{
								system("cls");
								cout << "Opçao invalida! \n";
								break;
							}
						}
					}
				
					break;
					
				case 4: // Menu de Clientes
					system("cls");
					menu="menu4";
					while(menu=="menu4"){
						titulo();
					cout<<"=========> Menu Clientes <========= \n\n";
					verificar();
					cout << "Digite uma opção: \n1 - Cadastrar Clientes\n2 - Buscar Clientes\n3 - Listar Clientes\n4 - Atualizar Dados\n5 - Excluir Cadastro\n0 - Voltar ao Menu Principal\n->";
					cin >> op1;
		
					switch(op1) {
			
						case 1:
						cad_Cliente();
						system("cls");
						break;
				
						case 2:
						buscar_clientes();
						cout<<"Aperte ENTER para voltar.\n";
						system("pause");
						system("cls");
						break;
			
						case 3:
						listar_clientes();
						cout<<"Aperte ENTER para voltar.\n";
						system("pause");
						system("cls");
						break;
				
						case 4:
						atualizar_clientes();
						cout<<"Aperte ENTER para voltar.\n";
						system("pause");
						system("cls");
						break;
			
						case 5:
						excluir_clientes();
						cout<<"Aperte ENTER para voltar.\n";
						system("pause");
						system("cls");
						break;
				
						case 0:
						system("cls");
						menu="0";
						break;
			
						default:
						system("cls");
						cout << "Opçao invalida! \n";
						break;	
					}
				}
					
					break;
				case 5: // Menu de Vendas
					system("cls");
					menu="menu5";
					while(menu=="menu5"){
						titulo();
					cout<<"=========> Menu Vendas <========= \n\n";
					verificar();
					cout << "Digite uma opção: \n1 - Cadastrar Venda\n2 - Buscar Venda\n3 - Listar Vendas\n4 - Atualizar Dados de Venda\n5 - Excluir Cadastro\n0 - Voltar ao Menu Principal\n->";
					cin>>op1;
					
					switch(op1){
						case 1:{
							cad_venda();
							system("cls");
							break;
						}
						case 2:{
							buscar_venda();
							cout<<"Para voltar aperte ENTER. \n\n";
            				system("pause");
            				system("cls");
							break;
						}
						case 3:{
							listar_venda();
							cout<<"Para voltar aperte ENTER. \n\n";
            				system("pause");
            				system("cls");
							break;
						}
						case 4:{
							atualizar_venda();
							cout<<"Aperte ENTER para voltar.\n";
							system("pause");
							system("cls");
							break;
						}
						case 5:{
							excluir_venda();
							cout<<"Aperte ENTER para voltar.\n";
							system("pause");
							system("cls");
							break;
						}
						case 0:{
							system("cls");
							menu="0";
							break;
						}
						default:{
							system("cls");
							cout << "Opçao invalida! \n";
							break;
						}
					}
					
				}	
				break;
				case 6: // Ajuda do Sistema
					system("cls");
					menu="menu6";
					while(menu=="menu6"){
						titulo();
					cout<<"=========> Ajuda do Sistema <========= \n\n";
					verificar();
					cout<<"1 - Login e Senha únicos, onde apenas o proprietário ira ter acesso ao sistema.\n";
					cout<<"2 - Fornecedores devem ser cadastrados previamente, assim como os Parceiros.\n";
					cout<<"3 - As Vendas devem ser cadastradas por último, pois necessitam de todas as informações completas.\n";
					cout<<"\n\nAperte ENTER para voltar ao menu principal.";
					system("Pause");
					menu="0";
					system("cls");
				}
					break;
					
				case 7:// Sobre o Sistema
					system("cls");
					menu="menu7";
					while(menu=="menu7"){
						titulo();
					cout<<"=========> Sobre o Sistema <========= \n\n";
					verificar();
					cout<<"Sistema desenvolvido por Artur, Emanuella, Júlia e Diego, para suprir a demanda\n";
					cout<<"interna da empresa GGHardware, com o intuito de registrar todo tipo de informação\n";
					cout<<"necessária para o funcionamento da loja. Sistema desenvolvido na linguagem C++.\n\n";
					cout<<"Todos os direitos reservados.\n\n";
					cout<<"\n\nAperte ENTER para voltar ao menu principal.";
					system("Pause");
					menu="0";
					system("cls");
				}
					break;
					
				case 0:
					start=0;
					titulo();
					cout<<"Até mais.";
					verificar();
					break;
					
				default:
					system("cls");
					cout<<"Opção inválida.\n";
					break;
		
			
		}
		
			

		
		
		
		
	}

}else{	//Erro de Senha
	system("cls");
	cout<<"Login ou Senha inválidos.\n";
}
}
	return 0;
}

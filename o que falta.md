Cliente: codcli, nome, rg, cpf, emial,cel, endereço,data nasc

Funcionário: codfunc, nome, data nasc, rg, cpf,cel, email, dataadm

Locação: codlocacao,codcli,dataloca, datadevo,valortotal,juro,desc,codcliente,codfunc,pagamento

Pagamento deve ser char e guardar o tipo de pagamento. 1- a vista 2 - prazo

Data de devolução são de 3 dias até 3 filmes e 4 dias mais de 3 filmes

Se pagamento a vista desconto de 5%

Se pagamento na devolução preço normal

Se atrasado, cobrar o valor da locação por dia de atraso.


Observações: Ao excluir um gênero verifique se tem algum filme cadastrado com esse gênero. 
Ao excluir um cliente verifique se tem alguma locação com este cliente. 
Ao excluir um funcionário verifique se tem alguma locação com este funcionário. 
Ao excluir uma locação, lembre-se de excluir também da tabela locação/filme. 
Liste o valor de todas as locações de filmes numa data específica. 
Listar os filmes que estão em atraso com seu valor original e seu valor com multa. 
O sistema deve ter a opção de devolução de filmes. 
Listar as devoluções. 

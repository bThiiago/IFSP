use geral;
-- 2
select estado,count(*) from cidades group by estado;
-- 3
select municipio,populacao from cidades order by populacao desc limit 5;
-- 4
select estado,count(*) as totcidade from cidades group by estado order by totcidade desc limit 5;
-- 5
select estado, sum(populacao) as total from cidades group by estado order by total desc limit 5;
-- 6 
with dados as (
  select estado,round(populacao*pcthomem/100,2) as homem, round(populacao*pctmulher/100,2) as mulher from cidades 
)  select estado,avg(homem),avg(mulher) from dados
   group by estado;
   
-- 7
with dados as (
  select estado,populacao, round(populacao*pcthomem/100,2) as homem, round(populacao*pctmulher/100,2) as mulher from cidades 
)  select estado,sum(populacao),avg(homem),avg(mulher) from dados 
   group by estado limit 10; 
   
-- 8 
select estado from cidades 
group by estado having avg(pctmulher)>=50;
   
-- 9
select estado from cidades 
group by estado having sum(pctmulher)>=sum(pcthomem);  

-- 10
select municipio from cidades where pctmulher = (select max(pctmulher) from cidades);

-- 11
select municipio,pctmulher,pcthomem,pcthomem-pctmulher as diferenca from cidades 
where pctmulher=(select min(pctmulher) from cidades);

-- 12
with dados as (
   select estado,min(populacao) as pop from cidades group by estado
) select estado,(select municipio from cidades where populacao=d.pop limit 1),pop from dados d;

-- 13
with dados as (
   select estado,max(populacao) as pop from cidades group by estado
) select estado,(select municipio from cidades where populacao=d.pop limit 1),pop from dados d order by pop desc limit 5;

-- 14
with dados as (
  select estado, round(populacao*pcthomem/100,2) as homem, round(populacao*pctmulher/100,2) as mulher from cidades 
)  select estado,sum(homem) as homem,sum(mulher) as mulher from dados 
   group by estado; 
   
-- 15   
Select left(municipio,1),sum(populacao) as populacao from cidades 
group by left(municipio,1);

-- 16
with dados as (
   select estado,populacao,pcthome,pctmulher from cidades where pcthomem>pctmulher
)
select estado,sum(populacao) from cidades
group by estado

   
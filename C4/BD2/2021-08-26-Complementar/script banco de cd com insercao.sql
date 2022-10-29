
use geral;

CREATE TABLE Gravadora (
       codgrav              SMALLINT    NOT NULL,
       nomegrav             VARCHAR(60) NULL,
       ender                VARCHAR(60) NULL,
       telefone             VARCHAR(20) NULL,
       contato              VARCHAR(20) NULL,
       url                  VARCHAR(80) NULL,
       PRIMARY KEY (codgrav)
);

CREATE TABLE CD (
       codcd                INTEGER       NOT NULL,
       codgrav              SMALLINT      NULL,
       nomecd               VARCHAR(60)   NULL,
       preco                DECIMAL(14,2) NULL,
       datalanc             DATE          NULL,
       indica               INTEGER       NULL,
       PRIMARY KEY (codcd),
       FOREIGN KEY (codgrav) REFERENCES Gravadora(codgrav),
       FOREIGN KEY (indica)  REFERENCES CD(codcd)
);

CREATE TABLE Musica (
       codmus               INTEGER      NOT NULL,
       nomemus              VARCHAR(60)  NULL,
       duracao              DECIMAL(6,2) NULL,
       PRIMARY KEY (codmus)
);

CREATE TABLE Autor (
       codaut            INTEGER     NOT NULL,
       nomeaut           VARCHAR(60) NULL,
       PRIMARY KEY (codaut) 
);

CREATE TABLE MusicaAutor (
       codmus           INTEGER NOT NULL,
       codaut           INTEGER NOT NULL,
       PRIMARY KEY (codmus, codaut),
       FOREIGN KEY (codaut) REFERENCES Autor (codaut),
       FOREIGN KEY (codmus) REFERENCES Musica(codmus) 
);

CREATE TABLE Faixa (
       codmus           INTEGER  NOT NULL,
       codcd            INTEGER  NOT NULL,
       num              SMALLINT NULL,
       PRIMARY KEY (codmus, codcd),
       FOREIGN KEY (codcd)  REFERENCES CD(codcd),
       FOREIGN KEY (codmus) REFERENCES Musica(codmus)
);

CREATE TABLE CDCategoria(
       codcat       SMALLINT      NOT NULL,
       menor        DECIMAL(14,2) NOT NULL,
       maior        DECIMAL(14,2) NOT NULL
);

DELETE FROM MusicaAutor;
DELETE FROM Autor;
DELETE FROM Faixa;
DELETE FROM Musica;
DELETE FROM CD;
DELETE FROM Gravadora;
DELETE FROM CDCategoria;

-- TABELA DE Autor
INSERT INTO Autor (codaut, nomeaut) VALUES ( 1, 'Renato Russo' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 2, 'Tom Jobim' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 3, 'Chico Buarque' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 4, 'Dado Villa-Lobos' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 5, 'Marcelo Bonfá' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 6, 'Ico Ouro-Preto' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 7, 'Vinicius de Moraes' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 8, 'Baden Powell' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 9, 'Paulo Cesar Pinheiro' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 10, 'João Bosco' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 11, 'Aldir Blanc' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 12, 'Joyce' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 13, 'Ana Terra' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 14, 'Cartola' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 15, 'Cláudio Tolomei' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 16, 'João Nogueira' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 17, 'Suely Costa' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 18, 'Guinga' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 19, 'Danilo Caymmi' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 20, 'Tunai' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 21, 'Sérgio Natureza' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 22, 'Heitor Villa Lobos' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 23, 'Ferreira Gullar' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 24, 'Catulo da Paixão Cearense' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 25, 'Zezé di Camargo' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 26, 'Niltinho Edilberto' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 27, 'Marisa Monte' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 28, 'Carlinhos Brown' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 29, 'Gonzaga Jr' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 30, 'Roberto Mendes' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 31, 'Ana Basbaum' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 32, 'Caetano Veloso' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 33, 'José Miguel Wisnik' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 34, 'Vevé Calazans' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 35, 'Gerônimo' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 36, 'Sérgio Natureza' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 37, 'Roberto Carlos' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 38, 'Erasmo Carlos' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 39, 'Renato Teixeira' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 40, 'Chico César' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 41, 'Vanessa da Mata' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 42, 'Jorge Portugal' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 43, 'Lilian Knapp' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 44, 'Renato Barros' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 45, 'Bebel Gilberto' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 46, 'Cazuza' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 47, 'Dé' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 48, 'Adriana Calcanhoto' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 49, 'Antonio Cícero' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 50, 'Paulo Machado' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 51, 'Dorival Caymmi' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 52, 'João Donato' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 53, 'Ronaldo Bastos' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 54, 'Barry Manilow' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 55, 'Richard Kerr' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 56, 'Chris Arnold' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 57, 'David Pomeranz' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 58, 'George Michael' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 59, 'S. Wonder' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 60, 'Elton John' );
INSERT INTO Autor (codaut, nomeaut) VALUES ( 61, 'Arnaldo Antunes' );


-- TABELA DE MÚSICA
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 1, 'Será',2.28 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 2, 'Ainda é Cedo', 3.55 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 3, 'Geração Coca-Cola', 2.20 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 4, 'Eduardo e Monica', 4.32 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 5, 'Tempo Perdido', 5.00 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 6, 'Índios', 4.23 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 7, 'Que País é Este',2.64 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 8, 'Faroeste Caboclo', 9.03 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 9, 'Há Tempos', 3.16 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 10, 'Pais e Filhos', 5.06 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 11, 'Meninos e Meninas', 3.22 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 12, 'Vento no Litoral', 6.05 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 13, 'Perfeição', 4.35 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 14, 'Giz', 3.20 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 15, 'Dezesseis', 5.28 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 16, 'Antes das Seis', 3.09 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 17, 'Meninos, Eu Vi', 3.25 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 18, 'Eu Te Amo', 3.06 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 19, 'Piano na Mangueira', 2.23 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 20, 'A Violeira', 2.54 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 21, 'Anos Dourados', 2.56 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 22, 'Olha, Maria', 3.55 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 23, 'Biscate', 3.20 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 24, 'Retrato em Preto e Branco', 3.03 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 25, 'Falando de Amor', 3.20 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 26, 'Pois É', 2.48 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 27, 'Noite dos Mascarados', 2.42 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 28, 'Sabiá', 3.20 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 29, 'Imagina', 2.52 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 30, 'Bate-Boca', 4.41 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 31, 'Cai Dentro', 2.41 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 32, 'O Bêbado e o Equilibrista', 3.47 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 33, 'Essa Mulher', 3.47 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 34, 'Basta de Clamares Inocência', 3.38 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 35, 'Beguine Dodói', 2.14 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 36, 'Eu hein Rosa', 3.36 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 37, 'Altos e Baixos', 3.29 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 38, 'Bolero de Satã', 3.32 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 39, 'Pé Sem Cabeça', 2.57 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 40, 'As Aparências Enganam', 4.18 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 41, 'É o Amor', 4.19 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 42, 'Trenzinho Caipira', 3.32 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 43, 'Luar do Sertão', 3.23 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 44, 'Não tenha Medo', 3.27 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 45, 'Eu queria que você viesse', 2.57 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 46, 'Espere por mim Morena', 3.04 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 47, 'Resto de mim', 2.59 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 48, 'Gema', 2.51 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 49, 'Cacilda', 2.22 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 50, 'Agradecer e abraçar', 3.30 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 51, 'As flores do jardim da nossa casa', 3.26 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 52, 'Romaria', 3.16 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 53, 'A força que nunca seca', 2.17 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 54, 'Vila do Adeus', 3.06 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 55, 'Devolva-me', 3.58 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 56, 'Mais Feliz', 2.50 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 57, 'Inverno', 4.40 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 58, 'Mentiras', 2.58 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 59, 'Esquadros', 3.10 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 60, 'Cariocas', 3.14 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 61, 'Vambora', 4.16 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 62, 'Por isso eu Corro Demais', 2.58 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 63, 'Maresia', 4.09 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 64, 'Metade', 3.25 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 65, 'Senhas', 3.37 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 66, 'Marina', 2.55 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 67, 'Naquela Estação', 4.46 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 68, 'Mandy', 3.18 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 69, 'New York City Rhythm', 4.41 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 70, 'Looks Like We Made It', 3.32 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 71, 'Daybreak', 3.05 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 72, 'Can''t Smile Without you', 3.13 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 73, 'It''s a Miracle', 3.53 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 74, 'Even Now', 3.29 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 75, 'Bandstand Boogie', 2.50 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 76, 'Trying to get the feeling again', 3.50 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 77, 'Some Kind of Friend', 4.02 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 78, 'Praying for Time', 3.52 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 79, 'Freedom 90', 3.52 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 80, 'They Won''t Go When I Go', 3.22 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 81, 'Something to Save', 4.10 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 82, 'Cowboys and Angels', 4.12 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 83, 'Don''t Let the Sun Go Down on Me', 3.45 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 84, 'Waiting for That Day', 2.58 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 85, 'Mothers Pride', 2.12 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 86, 'Heal the Pain', 3.02 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 87, 'Soul Free', 2.42 );
INSERT INTO Musica (codmus, nomemus, duracao ) VALUES ( 88, 'Waiting', 3.32 );


-- TABELA Gravadora
INSERT INTO Gravadora (codgrav, nomegrav, ender, url, contato ) VALUES ( 1, 'EMI', 'Rod. Pres. Dutra, s/n  km 229,8', 'www.emi-music.com.br', 'JOÃO' );
INSERT INTO Gravadora (codgrav, nomegrav, ender, url, contato ) VALUES ( 2, 'BMG', 'Av. Piramboia, 2898 - Parte 7', 'www.bmg.com.br', 'MARIA' );
INSERT INTO Gravadora (codgrav, nomegrav, ender, url, contato ) VALUES ( 3, 'SOM LIVRE', NULL, 'www.somlivre.com.br', 'MARTA' );
INSERT INTO Gravadora (codgrav, nomegrav, ender, url, contato ) VALUES ( 4, 'EPIC', NULL, 'www.epic.com.br', 'PAULO' );

-- TABELA CD
INSERT INTO CD (codcd, codgrav, nomecd, preco, datalanc ) VALUES ( 1, 1, 'Mais do Mesmo', 15.00, '1998-10-01' );
INSERT INTO CD (codcd, codgrav, nomecd, preco, datalanc ) VALUES ( 2, 2, 'Bate-Boca', 12.00, '1999-07-01' );
INSERT INTO CD (codcd, codgrav, nomecd, preco, datalanc ) VALUES ( 3, 3, 'Elis Regina - Essa Mulher', 13.00, '1989-05-01' );
INSERT INTO CD (codcd, codgrav, nomecd, preco, datalanc ) VALUES ( 4, 2, 'A Força que nunca Seca', 13.50, '1998-12-01' );
INSERT INTO CD (codcd, codgrav, nomecd, preco, datalanc ) VALUES ( 5, 3, 'Perfil', 10.50, '2001-05-01' );
INSERT INTO CD (codcd, codgrav, nomecd, preco, datalanc ) VALUES ( 6, 2, 'Barry Manilow Greatest Hits Vol I', 9.50, '1991-11-01' );
INSERT INTO CD (codcd, codgrav, nomecd, preco, datalanc ) VALUES ( 7, 2, 'Listen Without Prejudice', 9.00, '1991-10-01' );

UPDATE CD
   SET indica = 5
 WHERE codcd = 1;

UPDATE CD
   SET indica = 3
 WHERE codcd = 2;

UPDATE CD
   SET indica = 1
 WHERE codcd = 3;

UPDATE CD
   SET indica = 2
 WHERE codcd = 5;

UPDATE CD
   SET indica = 7
 WHERE codcd = 6;

UPDATE CD
   SET indica = 1
 WHERE codcd = 4;

-- TABELA ITEMCD
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 1, 1, 1 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 1, 2, 2 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 1, 3, 3 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 1, 4, 4 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 1, 5, 5 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 1, 6, 6 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 1, 7, 7 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 1, 8, 8 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 1, 9, 9 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 1, 10, 10 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 1, 11, 11 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 1, 12, 12 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 1, 13, 13 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 1, 14, 14 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 1, 15, 15 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 1, 16, 16 );
-- BATE-BOCA
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 2, 1, 17 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 2, 2, 18 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 2, 3, 19 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 2, 4, 20 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 2, 5, 21 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 2, 6, 22 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 2, 7, 23 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 2, 8 ,24 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 2, 9, 25 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 2, 10, 26 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 2, 11, 27 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 2, 12, 28 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 2, 13, 29 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 2, 14, 30 );
-- ESSA MULHER
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 3, 1, 31 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 3, 2, 32 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 3, 3, 33 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 3, 4, 34 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 3, 5, 35 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 3, 6, 36 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 3, 7, 37 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 3, 8 ,38 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 3, 9, 39 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 3, 10, 40 );
-- FORÇA QUE NUNCA SECA
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 4, 1, 41 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 4, 2, 42 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 4, 3, 43 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 4, 4, 44 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 4, 5, 45 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 4, 6, 46 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 4, 7, 47 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 4, 8 ,48 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 4, 9, 49 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 4, 10, 50 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 4, 11, 51 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 4, 12, 52 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 4, 13, 53 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 4, 14, 54 );
-- DEVOLVA-ME
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 5, 1, 55 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 5, 2, 56 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 5, 3, 57 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 5, 4, 58 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 5, 5, 59 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 5, 6, 60 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 5, 7, 61 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 5, 8 ,62 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 5, 9, 63 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 5, 10, 64 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 5, 11, 65 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 5, 12, 66 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 5, 13, 67 );
-- BARRY MANILOW
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 6, 1, 68 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 6, 2, 69 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 6, 3, 70 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 6, 4, 71 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 6, 5, 72 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 6, 6, 73 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 6, 7, 74 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 6, 8 ,75 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 6, 9, 76 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 6, 10, 77 );
-- LISTEN WITHOUT PREJUDICE
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 7, 1, 78 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 7, 2, 79 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 7, 3, 80 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 7, 4, 81 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 7, 5, 82 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 7, 6, 83 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 7, 7, 84 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 7, 8 ,85 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 7, 9, 86 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 7, 10, 87 );
INSERT INTO Faixa (codcd, num, codmus ) VALUES ( 7, 11, 88 );
-- TABELA MusicaAutor
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 1, 1 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 2, 5 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 2, 6 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 3, 4 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 3, 5 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 3, 1 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 4, 1 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 4, 4 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 5, 1 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 6, 1 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 7, 1 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 8, 1 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 9, 1 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 9, 4 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 9, 5 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 10, 1 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 10, 4 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 10, 5 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 11, 1 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 11, 4 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 11, 5 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 12, 1 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 12, 4 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 12, 5 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 13, 1 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 13, 4 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 13, 5 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 14, 1 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 14, 4 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 14, 5 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 15, 1 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 15, 4 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 15, 5 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 16, 1 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 16, 4 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 16, 5 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 17, 2 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 17, 3 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 18, 2 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 18, 3 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 19, 2 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 19, 3 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 20, 2 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 20, 3 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 21, 2 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 21, 3 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 22, 2 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 22, 3 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 22, 7 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 23, 3 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 24, 2 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 24, 3 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 25, 2 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 26, 2 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 26, 3 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 27, 3 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 28, 2 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 28, 3 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 29, 2 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 29, 3 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 30, 3 );
-- ESSA MULHER
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 31, 8 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 31, 9 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 32, 10 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 32, 11 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 33, 12 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 33, 13 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 34, 14 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 35, 10 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 35, 11 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 35, 15 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 36, 16 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 36, 9 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 37, 17 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 37, 11 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 38, 18 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 38, 9 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 39, 19 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 39, 13 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 40, 20 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 40, 21 );
-- A FORÇA QUE NUNCA SECA
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 41, 25 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 44, 26 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 45, 27 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 45, 28 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 46, 29 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 47, 30 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 47, 31 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 48, 32 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 49, 33 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 50, 35 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 50, 36 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 51, 37 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 51, 38 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 52, 39 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 53, 40 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 53, 41 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 54, 30 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 54, 42 );
-- DEVOLVA-ME
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 55, 43 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 55, 44 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 56, 45 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 56, 46 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 56, 47 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 57, 48 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 57, 49 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 58, 48 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 59, 48 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 60, 48 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 61, 48 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 62, 37 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 63, 50 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 63, 49 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 64, 48 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 65, 48 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 66, 51 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 67, 52 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 67, 53 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 67, 32 );
-- BARRY MANILOW
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 68, 55 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 69, 54 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 70, 55 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 71, 54 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 72, 56 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 73, 54 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 74, 54 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 75, 54 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 76, 57 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 77, 54 );
-- LISTEN WITHOUT PREJUDICE
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 78, 58 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 79, 58 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 80, 59 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 81, 58 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 82, 58 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 83, 60 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 84, 58 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 85, 58 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 86, 58 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 87, 58 );
INSERT INTO MusicaAutor (codmus, codaut ) VALUES ( 88, 58 );
-- TABELA CD_Categoria
INSERT INTO CDCategoria (codcat, maior, menor)
      VALUES ( 1,     5, 10), ( 2, 10.01, 12),
             ( 3, 12.01, 15), ( 4, 15.01, 20);

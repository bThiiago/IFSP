ALTER TABLE concurso
	ADD COLUMN posicao INT NOT NULL,
    ADD COLUMN nomeAux VARCHAR(100) DEFAULT NULL,
    ADD COLUMN cpf VARCHAR(14) DEFAULT NULL,
    ADD COLUMN situacao VARCHAR(15) DEFAULT NULL,
ADD COLUMN nota DECIMAL(10,2) DEFAULT NULL;

UPDATE concurso SET posicao = substring(nome, 1, locate(' ', nome));
UPDATE concurso SET nomeAux = substring(nome, locate(' ', nome) + 1, length(nome));
UPDATE concurso SET situacao = 'APROVADO';
UPDATE concurso SET nota = cast(REPLACE(RIGHT(trim(nome), 6), ',', '.') AS DECIMAL(10,2));
UPDATE concurso SET nomeAux = LEFT(nomeAux, locate('APROVADO', nomeAux) - 1);
UPDATE concurso SET cpf = RIGHT(trim(nomeAux), 14);
UPDATE concurso SET nomeAux = substring(trim(nomeAux), 1, length(trim(nomeAux)) - 15);
UPDATE concurso SET nome = nomeAux;
UPDATE concurso SET situacao = 'ELIMINADO' WHERE trim(nome) LIKE '%SILVA';
SELECT nome FROM concurso WHERE trim(nome) LIKE '%SILVA';

ALTER TABLE concurso
	DROP COLUMN nomeAux,
	ADD PRIMARY KEY (posicao),
CHANGE COLUMN nome nome VARCHAR(100) AFTER posicao;

SELECT * FROM concurso;
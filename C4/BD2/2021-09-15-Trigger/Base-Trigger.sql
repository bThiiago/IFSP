USE thiagobanco;

CREATE TABLE IF NOT EXISTS orcamento (
  idOrcamento INT NOT NULL,
  nomeCliente VARCHAR(200) NULL,
  telefone VARCHAR(15) NULL,
  valorTotal FLOAT NULL,
  orcamentocol VARCHAR(45) NULL,
  data DATE NULL,
  aprovacao DATE NULL,
  totalParcelas INT NULL,
PRIMARY KEY (idOrcamento));

CREATE TABLE IF NOT EXISTS produtos (
  idProdutos INT NOT NULL,
  produto VARCHAR(200) NULL,
  quantidade INT NULL,
  valor FLOAT NULL,
  precoCusto FLOAT NULL,
PRIMARY KEY (idProdutos));

CREATE TABLE IF NOT EXISTS itemOrcamento (
  idItem INT NOT NULL,
  quantidade INT NULL,
  valorPago FLOAT NULL,
  orcamento_idOrcamento INT NOT NULL,
  produtos_idProdutos INT NOT NULL,
  PRIMARY KEY (idItem, orcamento_idOrcamento),
  INDEX fk_itemOrcamento_orcamento_idx (orcamento_idOrcamento ASC) VISIBLE,
  INDEX fk_itemOrcamento_produtos1_idx (produtos_idProdutos ASC) VISIBLE,
  CONSTRAINT fk_itemOrcamento_orcamento
    FOREIGN KEY (orcamento_idOrcamento)
    REFERENCES orcamento (idOrcamento)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT fk_itemOrcamento_produtos1
    FOREIGN KEY (produtos_idProdutos)
    REFERENCES produtos (idProdutos)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);

CREATE TABLE IF NOT EXISTS cliente (
  idCliente INT NOT NULL,
  nome VARCHAR(200) NULL,
  telefone VARCHAR(15) NULL,
  PRIMARY KEY (idCliente));

CREATE TABLE IF NOT EXISTS venda (
  idVenda INT NOT NULL,
  data DATE NULL,
  valorTotal FLOAT NULL,
  cliente_idCliente INT NOT NULL,
  PRIMARY KEY (idVenda),
  INDEX fk_venda_cliente1_idx (cliente_idCliente ASC) VISIBLE,
  CONSTRAINT fk_venda_cliente1
    FOREIGN KEY (cliente_idCliente)
    REFERENCES cliente (idCliente)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);

CREATE TABLE IF NOT EXISTS itemCompra (
  idItemCompra INT NOT NULL,
  quantidade INT NULL,
  valorPago FLOAT NULL,
  venda_idVenda INT NOT NULL,
  produtos_idProdutos INT NOT NULL,
  PRIMARY KEY (idItemCompra, venda_idVenda),
  INDEX fk_itemCompra_venda1_idx (venda_idVenda ASC) VISIBLE,
  INDEX fk_itemCompra_produtos1_idx (produtos_idProdutos ASC) VISIBLE,
  CONSTRAINT fk_itemCompra_venda1
    FOREIGN KEY (venda_idVenda)
    REFERENCES venda (idVenda)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT fk_itemCompra_produtos1
    FOREIGN KEY (produtos_idProdutos)
    REFERENCES produtos (idProdutos)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);

CREATE TABLE IF NOT EXISTS pagamento (
  idPagamento INT NOT NULL,
  vencimento DATE NULL,
  valor FLOAT NULL,
  pagamento VARCHAR(45) NULL,
  venda_idVenda INT NOT NULL,
  PRIMARY KEY (venda_idVenda),
  CONSTRAINT fk_pagamento_venda1
    FOREIGN KEY (venda_idVenda)
    REFERENCES venda (idVenda)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);
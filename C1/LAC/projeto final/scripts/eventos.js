function AltoContraste(){
    console.log("Funcao ativar alto contraste");
    
    var corAtual, elementoBody;

    elementoBody = document.getElementsByTagName("body")[0];
    
    corAtual = elementoBody.style.backgroundColor;
    console.log("cor atual: " + corAtual);
    
    elementoBody.style.backgroundColor = "black";
    elementoBody.style.color = "white";
    
}

function Normal(){
    console.log("Funcao voltar a pagina ao normal");

    var corAtual, elementoBody;

    elementoBody = document.getElementsByTagName("body")[0];
    
    corAtual = elementoBody.style.backgroundColor;
    console.log("cor atual: " + corAtual);

    elementoBody.style.backgroundColor = "white";
    elementoBody.style.color = "black";

}

function Extra(){
    console.log("Funcao tema extra");

    var corAtual, elementoBody;

    elementoBody = document.getElementsByTagName("body")[0];
    
    corAtual = elementoBody.style.backgroundColor;
    console.log("cor atual: " + corAtual);

    elementoBody.style.backgroundColor = "#282c34";
    elementoBody.style.color = "white";

}

window.onload = function(){
    console.log("Entrou no window onload");

    document.getElementById("Normal").addEventListener("click", Normal);
    document.getElementById("Contraste").addEventListener("click", AltoContraste);
    document.getElementById("Extra").addEventListener("click", Extra);

}
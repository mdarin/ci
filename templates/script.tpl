({
unitName: "{$imitator}",
	processEvent: function(domain, name, param)
	{
		print("processEvent: " + domain + " " + name + " " + param);
		return process(domain, name, param)
	},
	processICCEvent: function()
	{
		print ("processIICEvent" );
		print ("src_complex " + arguments[0]);
		print ("src_imitator " + arguments[1]);
		print("nparams ");
		for (var i = 2; i < arguments.length; i+=2) 
		{
			print("name: " + arguments[i]);
			print("value: " + arguments[i+1]);
		}
		processIIC (arguments);
	}, 
	processDisrepair: function(x)
	{
		print ("disrepair"+x);
		return processDisrep(x)
	},
	init: function()
	{
		print ("init");
	},
	fini: function()
	{
		print ("fini");
	},

});

/**
* выполняет дествия или вызывает функции в зависимости от
* имени и состояния управляющего элемента(кнопка, тумблер ...)
*
* ПОЛУЧАЕТ:
* domain домен управляющего элемента
* name имя управляющего элемента
* param состояние управляющего элемента
* 
* ВОЗВРАШАЕТ:
* void
*/
function process(domain, name, param)
{
		print("**  [logic]->event processed");	 
		switch (name) {
		// Код написанный далее иллюстрирует порядокn
		// механизм обработки событий поступающих от элементов формыn
		case "SA1":
		  switch(param) {
		  case "1":
			Model.setParam("HL1", 1);
			break;
		  default:
		    Model.setParam("HL1", 0);
		    break;
		  }
		  break;
		default:
		  break;
		}
}

/**
* выполняет дествия или вызывает функции в зависимости от 
* сообщения и параметров, полученных от другого устройства или бода
*
* ПОЛУЧАЕТ:
* arguments[0] комплекс устройства, приславшего сообщение
* arguments[1] имя устройства, приславшего сообщение
* arguments[2] сообщение
* arguments[3] параметры присланные вместе с сообщением
* 
* ВОЗВРАШАЕТ:
* void
*/
function processIIC (arguments) {
		switch (arguments[2]) {

		}

}

/**
* выполняет дествия или вызывает функции в зависимости от 
* сообщения, полученного от ПРЗ
*
* ПОЛУЧАЕТ:
* x сообщение от ПРЗ
* 
* ВОЗВРАШАЕТ:
* void
*/
function processDisrep(x) {

}

/**
* ХЗ что делает :)
*
* ПОЛУЧАЕТ:
* name
* param 
*
* ВОЗВРАШАЕТ:
* void
*/
function ext(name, param)
{
    print("ext: " + name + " " + param);
}

// -------------------------------------------- nothing yet  ----------------------------------------------------

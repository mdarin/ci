/* * * * *
 * Название: ci - генератор заготовок имитаторов
 * Версия: 0.2.0
 * Описание: программа создаёт и размещает комплект файлов 
 *  имитатора или набора имитаторов. Сгенерированный 
 *  конмплект необходимо сделать исполняемым, для этого
 *  необходимо скомпилировать враппер(ы) и панель(и) для
 *  каждого сгенерированного имитатора. В результате после
 *  запуска на экране появится окно с одним тумблером и одним
 *  диодом, для которых из шаблона сгенерирована логика:
 *  при переключении тумблера диод загорается и гаснет.
 * Программист разработчик: Дарьин М.В.
 * Программист сопровождения:
 * Дата создания: 07.12.2012
 * Дата последнего изменения: 26.03.2013
 * Организация: ЗАО "ОКБ "ИКАР"
 * Лицензия: "AS-IS" "NO WARRENTY"
 * Контакты:
 * почта: 
 * адрес: 
 * 
 * 2012
 * 
 * * */ 


#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <string.h>

/*
  Объявление констант
*/

extern FILE *yyin, *yyout;
char ImitatorName[256] = {0};
char ComplexName[256] = {0};
char ProfileName[256] = {0};
char *ProjectRoot = NULL;
char IpanelsDir[256] = {0};
char WrappersVirtualDir[256] = {0};
char IcfgDir[256] = {0};
char ProfileDir[256] = {0};
char ScriptsDir[256] = {0};
char TemplatesDir[256] = {0};


/*
  Объявление структур данных
*/




/*
  Объявление макроподстановок
*/

//__DEBUG 
// если определён, то отладочный режим = ВКЛ
#define DEBUG 1
// иначе отладочный режим = ВЫКЛ
#undef DEBUG


#define get_vsn() ("0.2.0")
#define get_usage() ("Usage: ci [OPTIONS] COMPLEX IMITATOR PROFILE\n"\
"\n"\
"Create IMITATOR(s)"\
"\n"\
"  -c | --complex\n"\
"  -v | --version\n"\
"  -h | --help")



#define get_ext(FileType) ("")
#define get_ext_cpp() ("cpp")
#define get_ext_h() ("h")
#define get_ext_ui() ("ui")
#define get_ext_pro() ("pro")
#define get_ext_js() ("js")
#define get_ext_prfl() ("prfl")
#define get_ext_xml() ("xml")

#define get_nfiles() (12)
#define process_nomem_data(Data) (NULL)


#define get_filename() ("hello_world")
#define get_mode() ("w")

// пути для размещения сгенерированных файлов
#ifdef DEBUG
#define get_project_root_dir() ("C:\\temp")
#define get_ipanels_dir() ("C:\\temp\\ipanels")
#define get_wrappers_dir() ("C:\\temp\\wrappers")
#define get_virtual_wrappers_dir() ("C:\\temp\\wrappers\\virtual")
#define get_icfg_dir() ("C:\\temp\\icfg")
#define get_complexes_dir() ("C:\\temp\\icfg\\complexes")
#define get_profile_dir() ("C:\\temp\\icfg\\profile")
#define get_scripts_dir() ("C:\\temp\\scripts")
#else
#define get_project_root_dir() ("C:\\Project\\ikar2")
#define get_ipanels_dir() ("C:\\Project\\ikar2\\ipanels")
#define get_wrappers_dir() ("C:\\Project\\ikar2\\wrapper")
#define get_virtual_wrappers_dir() ("C:\\Project\\ikar2\\wrappers\\virtual")
#define get_icfg_dir() ("C:\\Project\\ikar2\\icfg")
#define get_complexes_dir() ("C:\\Project\\ikar2\\icfg\\complexes")
#define get_profile_dir() ("C:\\Project\\ikar2\\icfg\\profile")
#define get_scripts_dir() ("C:\\Project\\ikar2\\scripts")
#endif 


// имена каталога и файлов шаблонов для генерирования выходных файлов
#define get_templates_dir() ("C:\\project\\ikar2\\utils\\ci\\templates")
#define get_prf_tpl() ("prf.tpl")
#define get_cfg_tlp() ("cfg.tpl")
#define get_script_tpl() ("script.tpl")
#define get_wrapper_virtual_cpp_tpl() ("wrapper_virtual_cpp.tpl")
#define get_wrapper_virtual_h_tpl() ("wrapper_virtual_h.tpl")
#define get_wrapper_virtual_pro_tpl() ("wrapper_virtual_pro.tpl")
#define get_panel_cpp_tpl() ("panel_cpp.tpl")
#define get_panel_h_tlp() ("panel_h.tpl")
#define get_panel_pro_tpl() ("panel_pro.tpl")
#define get_panel_ui_tpl() ("panel_ui.tpl")
#define get_panel_ipanel_h_tpl() ("panel_ipanel_h.tpl")
#define get_panel_main_cpp_tpl() ("panel_main_cpp.tpl")



#define SUCCESS 0
#define FAILURE -1



/*
  Объявление прототипов функций
*/

/* *
 * -------------------------------------------------------
 * Function:
 * Input:
 * Output:
 * Description:
 */
char *get_fullpath(char *path, char *dir, char *file, char *extention, char *separator)
{  
  path = NULL;
  if ( NULL != dir && NULL != file && NULL != extention && NULL != separator) {
		strcat(path, dir);   
		strcat(path, file);  
		strcat(path, separator);   
		strcat(path, extention);
	}
	return path;
}


/* *
 * -------------------------------------------------------
 * Function:
 * Input:
 * Output:
 * Description:
 */
int generate_file(const char *GeneratedFileName, char *TepmlateFileName)
{
    int Status = 0;
#ifdef DEBUG		
		printf("\n:: template: %s\n:: generated file: %s\n", GeneratedFileName, TepmlateFileName);
#endif	    
    yyin = fopen(TepmlateFileName, "r");
		yyout = fopen(GeneratedFileName, "w+");
	if (NULL != yyin && NULL != yyout) {
#ifdef DEBUG		
		printf("\n:: lex starts   ok\n");
#endif		
		Status = yylex();
#ifdef	DEBUG   	
		printf("\n:: tex terminated   [ ok ] with status: %d\n", Status);
#endif
	}
	if (SUCCESS != fclose(yyin) && SUCCESS != fclose(yyout)) {   
	//FAILURE
        Status = -1;//CANT_CLOSE_FILE;
#ifdef DEBUG        
        fprintf(stdout, "Can't close output file: %s!", yyout);
#endif   
    }
#ifdef DEBUG      
    printf("\n:: lex done!\n");
#endif
    return Status;
}

/* *
 * -------------------------------------------------------
 * Function:
 * Input:
 * Output:
 * Description:
 */
int create_dir_tree(char *Imitator)
{
 /* direct.h
int chdir(char* path)
int chdrive(int drive)
char* getcwd(char* buffer, size_t length)
int getdrive(void)
int mkdir(const char* pathname)
int rmdir(const char* pathname)
void fnmerge(char* path, const char* drive, const char* dir, const char* name, const char* ext)
int fnsplit(const char* path, char* drive, char* dir, char* name, char* ext)
char* searchpath(const char* file)
*/
	
#ifdef DEBUG	
	mkdir(get_wrappers_dir());
	mkdir(get_ipanels_dir());
	mkdir(get_scripts_dir());
	mkdir(get_icfg_dir());
	mkdir(get_profile_dir());
	mkdir(get_virtual_wrappers_dir());
#endif
	// перейти в каталог виртуальных врапперов
	chdir(WrappersVirtualDir);
	// создать каталог виртуального враппера для генерируемого имитатора
	mkdir(Imitator);
	// перейти в каталог виртуальных панелей
	chdir(IpanelsDir);
	// создать каталог виртуальной панели для генерируемого имитатора
	mkdir(Imitator);
	
	return SUCCESS;
}


/* *
 * -------------------------------------------------------
 * Function:
 * Input:
 * Output:
 * Description:
 */
int create_imitator(void)
{
//TODO: надо потом будет что-то поразумней придумать... 
 int Status = SUCCESS;
  #ifdef DEBUG	
  printf("\nproject root: %s\nvitr wrap dir: %s\nipanel dir: %s\nicfg dir: %s\nprofile dir: %s",	
		            get_project_root_dir(),
					get_virtual_wrappers_dir(),
					get_ipanels_dir(),
					get_icfg_dir(),
					get_profile_dir());				
  #endif
		
  char GeneratingFile[256] = {0};
  char Template[256] = {0};
		
  // подготовить имя файла шаблона для генерации файла вроппера .cpp
  strcpy(Template, TemplatesDir);
  strcat(Template, "//wrapper_virtual_cpp.tpl");
		
  create_dir_tree(ImitatorName);
		
  // подготовить имя файла .cpp виртуального враппера генерируемого имитатора
  strcpy(GeneratingFile, WrappersVirtualDir);
  strcat(GeneratingFile, "//");
  strcat(GeneratingFile, ImitatorName); 
  strcat(GeneratingFile, "//");
  strcat(GeneratingFile, "virtualwrapper");
  strcat(GeneratingFile, ImitatorName);
  strcat(GeneratingFile, ".");
  strcat(GeneratingFile, get_ext_cpp());
  
  #ifdef DEBUG
  printf("\ntemplate: %s\ngenerating file: %s", Template, GeneratingFile);
  #endif
  
  // сгененрировать файл враппера .cpp
  generate_file(GeneratingFile, Template);
  
  // подготовить имя файла шаблона для генерации файла вроппера .h
  strcpy(Template, TemplatesDir);
  strcat(Template, "//wrapper_virtual_h.tpl");
  
  // подготовим имя файла .h виртуального враппера генерируемого имитатора
  strcpy(GeneratingFile, WrappersVirtualDir);
  strcat(GeneratingFile, "//");
  strcat(GeneratingFile, ImitatorName); 
  strcat(GeneratingFile, "//");
  strcat(GeneratingFile, "virtualwrapper");
  strcat(GeneratingFile, ImitatorName);
  strcat(GeneratingFile, ".");
  strcat(GeneratingFile, get_ext_h());    
  
  #ifdef DEBUG
  printf("\ntemplate: %s\ngenerating file: %s", Template, GeneratingFile);
  #endif
  
  // сгененрировать файл враппера .pro
  generate_file(GeneratingFile, Template);
  
  // подготовить имя файла шаблона для генерации файла вроппера .pro
  strcpy(Template, TemplatesDir);
  strcat(Template, "//wrapper_virtual_pro.tpl");
  
  // подготовим имя файла .pro виртуального враппера генерируемого имитатора
  strcpy(GeneratingFile, WrappersVirtualDir);
  strcat(GeneratingFile, "//");
  strcat(GeneratingFile, ImitatorName); 
  strcat(GeneratingFile, "//");
  strcat(GeneratingFile, ImitatorName);
  strcat(GeneratingFile, ".");
  strcat(GeneratingFile, get_ext_pro());
  
  #ifdef DEBUG
  printf("\ntemplate: %s\ngenerating file: %s", Template, GeneratingFile);
  #endif
  
  // сгененрировать файл враппера .pro
  generate_file(GeneratingFile, Template);
  
  // подготовить имя файла шаблона для генерации файла виртуальной панели .pro
  strcpy(Template, TemplatesDir);
  strcat(Template, "//panel_pro.tpl");
  
  // подготовим имя файла .pro виртуальной панели генерируемого имитатора
  strcpy(GeneratingFile, IpanelsDir);
  strcat(GeneratingFile, "//");
  strcat(GeneratingFile, ImitatorName); 
  strcat(GeneratingFile, "//");
  strcat(GeneratingFile, ImitatorName);
  strcat(GeneratingFile, ".");
  strcat(GeneratingFile, get_ext_pro());
  
  #ifdef DEBUG
  printf("\ntemplate: %s\ngenerating file: %s", Template, GeneratingFile);
  #endif
  
  // сгененрировать файл виртуальной панели .pro
  generate_file(GeneratingFile, Template);
  
  // подготовить имя файла шаблона для генерации файла виртуальной панели .cpp
  strcpy(Template, TemplatesDir);
  strcat(Template, "//panel_cpp.tpl");
  
  // подготовим имя файла .cpp виртуальной панели генерируемого имитатора
  strcpy(GeneratingFile, IpanelsDir);
  strcat(GeneratingFile, "//");
  strcat(GeneratingFile, ImitatorName); 
  strcat(GeneratingFile, "//");
  strcat(GeneratingFile, ImitatorName);
  strcat(GeneratingFile, ".");
  strcat(GeneratingFile, get_ext_cpp());    
  
  #ifdef DEBUG
  printf("\ntemplate: %s\ngenerating file: %s", Template, GeneratingFile);
  #endif
  
  // сгененрировать файл виртуальной панели .h
  generate_file(GeneratingFile, Template);
  
  // сгененрировать файл виртуальной панели .h
  generate_file(GeneratingFile, Template);
  
  // подготовить имя файла шаблона для генерации файла виртуальной панели .h
  strcpy(Template, TemplatesDir);
  strcat(Template, "//panel_h.tpl");
  
  // подготовим имя файла .h виртуальной панели генерируемого имитатора
  strcpy(GeneratingFile, IpanelsDir);
  strcat(GeneratingFile, "//");
  strcat(GeneratingFile, ImitatorName);
  strcat(GeneratingFile, "//");
  strcat(GeneratingFile, ImitatorName);
  strcat(GeneratingFile, ".");
  strcat(GeneratingFile, get_ext_h());
  
  #ifdef DEBUG
  printf("\ntemplate: %s\ngenerating file: %s", Template, GeneratingFile);
  #endif
  
  // сгененрировать файл виртуальной панели .h
  generate_file(GeneratingFile, Template);
  
  // подготовить имя файла шаблона для генерации файла виртуальной панели .ui
  strcpy(Template, TemplatesDir);
  strcat(Template, "//panel_ui.tpl");
  
  // подготовим имя файла .ui виртуальной панели генерируемого имитатора
  strcpy(GeneratingFile, IpanelsDir);
  strcat(GeneratingFile, "//");
  strcat(GeneratingFile, ImitatorName);
  strcat(GeneratingFile, "//");
  strcat(GeneratingFile, ImitatorName);
  strcat(GeneratingFile, ".");
  strcat(GeneratingFile, get_ext_ui());
  
  #ifdef DEBUG
  printf("\ntemplate: %s\ngenerating file: %s", Template, GeneratingFile);
  #endif
  
  // сгененрировать файл виртуальной панели .ui
  generate_file(GeneratingFile, Template);
  
  // подготовить имя файла шаблона для генерации файла виртуальной панели ipanel.h
  strcpy(Template, TemplatesDir);
  strcat(Template, "//panel_ipanel_h.tpl");
  
  // подготовим имя файла ipanel.h виртуальной панели генерируемого имитатора
  strcpy(GeneratingFile, IpanelsDir);
  strcat(GeneratingFile, "//");
  strcat(GeneratingFile, ImitatorName);
  strcat(GeneratingFile, "//");
  strcat(GeneratingFile, "ipanel");
  strcat(GeneratingFile, ".");
  strcat(GeneratingFile, get_ext_h());
  
  #ifdef DEBUG
  printf("\ntemplate: %s\ngenerating file: %s", Template, GeneratingFile);
  #endif
  
  // сгененрировать файл виртуальной панели ipanel.h
  generate_file(GeneratingFile, Template);
  
  
  // ------------------------
  // Файл логики работы имитатора
  // ------------------------
  // подготовить имя файла шаблона для генерации файла логики работы .js
  strcpy(Template, TemplatesDir);
  strcat(Template, "//script.tpl");
  
  // подготовим имя файла .js логики генерируемого имитатора
  strcpy(GeneratingFile, ScriptsDir);
  strcat(GeneratingFile, "//");
  strcat(GeneratingFile, ImitatorName);
  strcat(GeneratingFile, ".");
  strcat(GeneratingFile, get_ext_js());    
  
  #ifdef DEBUG
  printf("\ntemplate: %s\ngenerating file: %s", Template, GeneratingFile);
  #endif
  
  // сгененрировать файл логики .js
  generate_file(GeneratingFile, Template);
  
  // ------------------------
  // Файл конфигурации имитатора или нескольких имитаторов(комплекса)
  // ------------------------
  // подготовить имя файла шаблона для генерации файла конфигурации .xml
  strcpy(Template, TemplatesDir);
  strcat(Template, "//cfg.tpl");
  
  // подготовим имя файла .xml конфигурации имитатора
  strcpy(GeneratingFile, IcfgDir);
  strcat(GeneratingFile, "//");
  strcat(GeneratingFile, ComplexName);
  strcat(GeneratingFile, ".");
  strcat(GeneratingFile, get_ext_xml());    
  
  #ifdef DEBUG
  printf("\ntemplate: %s\ngenerating file: %s", Template, GeneratingFile);
  #endif
  
  // сгененрировать файл конфигурации .xml
  generate_file(GeneratingFile, Template);
  
  // ------------------------
  // Файл профиля .prfl
  // ------------------------
  // подготовить имя файла шаблона для генерации файла профиля .prfl
  strcpy(Template, TemplatesDir);
  strcat(Template, "//prf.tpl");
  
  // подготовим имя файла .prfl профиля генерируемого имитатора
  strcpy(GeneratingFile, ProfileDir);
  strcat(GeneratingFile, "//");
  //strcat(GeneratingFile, "prf_");
  strcat(GeneratingFile, ProfileName);
  strcat(GeneratingFile, ".");
  strcat(GeneratingFile, get_ext_prfl());
  
  #ifdef DEBUG
  printf("\ntemplate: %s\ngenerating file: %s", Template, GeneratingFile);
  #endif
  
  // сгененрировать файл профиля .pffl
  generate_file(GeneratingFile, Template);
  return Status;	
}

/* *
 * -------------------------------------------------------
 * Function:
 * Input:
 * Output:
 * Description:
 */
void initialize_dirstruct(void)
{
  strcpy(IpanelsDir, ProjectRoot);
  strcat(IpanelsDir, "\\ipanels");

  strcpy(IcfgDir, ProjectRoot);
  strcat(IcfgDir, "\\icfg");

  strcpy(ProfileDir, IcfgDir);
  strcat(ProfileDir, "\\profile");

  strcpy(WrappersVirtualDir, ProjectRoot);
  strcat(WrappersVirtualDir, "\\wrappers\\virtual");

  strcpy(ScriptsDir, ProjectRoot);
  strcat(ScriptsDir, "\\scripts");

  strcpy(TemplatesDir, ProjectRoot);
  strcat(TemplatesDir, "\\utils\\ci\\templates");

  printf("ipanels: %s\nicfg: %s\nprofile: %s\nvirtual: %s\nscripts: %s\n", IpanelsDir, IcfgDir, ProfileDir, WrappersVirtualDir, ScriptsDir);

  return;
}

/* *
 * -------------------------------------------------------
 * Function:
 * Input:
 * Output:
 * Description:
 */
int main(int argc, char **argv)
{
	//char *Omninames = getenv("IKAR_ROOT");
	//printf("%s\n", Omninames);
	ProjectRoot = getenv("IKAR_ROOT");
	if (NULL == ProjectRoot) {
	  printf("%s:Can't find IKAR_ROOT env variable, please setup and try again.\n", argv[0]);
	  exit(0);
	}
	printf("IKAR_ROOT: [%s]\n", ProjectRoot);
	initialize_dirstruct();
	switch(argc){
	case 0:
	case 1:
	case 2:
	    printf("\ncreate imitator v.%s\n\n%s", get_vsn(), get_usage());
		break;
	case 4: // Генерировать один имитатор
		#ifdef DEBUG
		printf("\ninfile: %s\noutfile: %s.pro", argv[1], argv[2]);
		#endif
		
		strcpy(ImitatorName,"imitator_hello_world");
		strcpy(ComplexName,"сomplex_hello_world");
		strcpy(ProfileName, "profile_hello_world");
		
		if (NULL != argv[2]) {
			strcpy(ImitatorName,argv[2]);
		}
		if (NULL != argv[1]) {
		  	strcpy(ComplexName, argv[1]);
		}
		if (NULL != argv[3]) {
		  	strcpy(ProfileName, argv[argc-1]);
		}
			
		create_imitator();
		printf("\nImitator: %s created successfull!", ImitatorName);
		break;
	/*case 4:
	    printf("\ninfile: %s\noutfile: %s\nimitator name: %s", argv[1], argv[2], argv[3]);
	    char fout[256] = {0};
	    strcat(fout, argv[2]);
	    strcat(fout,".pro");
	    yyin = fopen(argv[1], "r");
		yyout = fopen(fout, "w+");
		strcat(ImitatorName,argv[3]);
		if(NULL != yyin && NULL != yyout)
		{
			yylex();
		}
		fclose(yyin);
		fclose(yyout);
	    break;*/
	default:	
		strcpy(ImitatorName,"imitator_hello_world");
		strcpy(ComplexName,"сomplex_hello_world");
		strcpy(ProfileName, "profile_hello_world");
		
		if (NULL != argv[1]) {
		  	strcpy(ComplexName, argv[1]);
		}
		
		if (NULL != argv[3]) {
		  	strcpy(ProfileName, argv[argc-1]);
		}
		
		// пропустить название комплекса
		int imitator = 2;
		// исключить название профиля
		int nimitators = argc - 2;
		// генерировать имитаторы пока не закончится список
		char **ImitatorsList = argv;
		do {		
			strcpy(ImitatorName, ImitatorsList[imitator]);
			create_imitator();
			printf("\nImitator: %s created successfull!", ImitatorName);
		#ifdef DEBUG
			printf("::%s\n", ImitatorsList[imitator]); 
		#endif
		} while (imitator++ < nimitators);
		
		break;
	} // eof switch

	exit(SUCCESS);
}

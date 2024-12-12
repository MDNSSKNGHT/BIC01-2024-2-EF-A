#include <iostream>

using namespace std;

string eventos[] = {
	"[2024-10-27 10:30:00] ERROR Conexión fallida al servidor.",
	"[2024-10-27 10:31:00] WARNING Disco casi lleno.",
	"[2024-10-27 10:32:00] INFO Sistema operativo iniciado correctamente.",
	"[2024-10-27 10:33:00] ERROR Error crítico en el módulo X.",
	"[2024-10-27 10:34:00] WARNING Posible fuga de memoria.",
	"[2024-10-27 10:35:00] INFO Proceso completado.",
	"[2024-10-27 10:36:00] UNKNOWN Mensaje desconocido.",
};

int main()
{
	int err, err_i, warn, info, unknown;

	err = warn = info = unknown = 0;

	cout << "Mensajes de ERROR: " << endl;

	for (int i = 0; i < 7; i++) {
		if ((err_i = eventos[i].find("ERROR", 0)) != string::npos) {
			err++;
			cout << '\t' << eventos[i].substr(err_i + 5, eventos[i].size()) << endl;
		} else if (eventos[i].find("WARNING", 0) != string::npos) {
			warn++;
		} else if (eventos[i].find("INFO", 0) != string::npos) {
			info++;
		} else if (eventos[i].find("UNKNOWN", 0) != string::npos) {
			unknown++;
		}
	}

	cout << "Cantidad de mensajes por tipo:" << endl;
	cout << "ERROR: " << err << endl;
	cout << "WARNING: " << warn << endl;
	cout << "INFO: " << info << endl;
	cout << "UNKNOWN: " << unknown << endl;

	return 0;
}

#include "pch.h"
#include <iostream>
#include <string>
#include "Structs.h"
using namespace std;

int main()
{
	Automovil* automovilPrueba = automovilCreate("Ford", "Focus", ALTA, 2017, 450000, 0);
	Factura* facturaDePrueba = venderAuto(B, automovilPrueba, "20190607", "Tomas Merencio", Contado);
	Movimiento* movimientoPrueba = movimientoCreate("13:00", facturaDePrueba);
	movimientoCrearAsientos(movimientoPrueba);
	LibroDiario* libroDiarioPrueba = libroDiarioCreate();
	listaMovimientosAgregaMovimiento(libroDiarioPrueba, movimientoPrueba);
	CicloEconomico* cicloEconomicoPrueba = cicloEconomicoCreate(2019, libroDiarioPrueba);
	ListaCiclosEconomicos* listaCiclosEconomicosPrueba = listaCiclosEconomicosCreate();
	listaCiclosEconomicosAgregaCiclo(listaCiclosEconomicosPrueba, cicloEconomicoPrueba);

	cout << "Caso CONTADO" << endl;
	mostrarLeyenda(movimientoPrueba);
	movimientoMostraDetalle(movimientoPrueba);

	cout << endl << "Caso FINANCIADO" << endl;
	Automovil* otroAutomovilPrueba = automovilCreate("Volkswagen", "Fox", MEDIA, 2019, 600000, 0);
	Factura* otraFacturaDePrueba = venderAuto(A, otroAutomovilPrueba, "20190524", "Ezequiel Escobar", Financiado);
	Movimiento* otroMovimientoPrueba = movimientoCreate("15:00", otraFacturaDePrueba);
	movimientoCrearAsientos(otroMovimientoPrueba);
	mostrarLeyenda(otroMovimientoPrueba);
	movimientoMostraDetalle(otroMovimientoPrueba);
}

string automovilMostraGama(Automovil* unAutomovil) {
	switch (unAutomovil->gama) {
	case 1: return "baja";
	break;
	case 2: return "media";
	break;
	case 3: return "alta";
	break;
	}
}

string facturaMostraFormaDePago(Factura* unaFactura) {
	switch (unaFactura->formaDePago) {
	case 1: return "al contado";
		break;
	case 2: return "financiado";
		break;
	case 3: return "parcialmente financiado";
		break;
	}
}

string facturaMostraTipo(Factura* unaFactura) {
	switch (unaFactura->tipoFactura) {
	case 1: return "A";
		break;
	case 2: return "B";
		break;
	case 3: return "C";
		break;
	}
}

void mostrarLeyenda(Movimiento* movimientoPrueba) {
	cout << "Kontarine necesita registrar la venta de un " <<
		movimientoPrueba->factura->automovilVendido->marca << " " <<
		movimientoPrueba->factura->automovilVendido->modelo <<
		" que se realizo el " << movimientoPrueba->factura->fecha.substr(6, 2) << "/" <<
		movimientoPrueba->factura->fecha.substr(4, 2) << "/" <<
		movimientoPrueba->factura->fecha.substr(0, 4) <<
		", cuyo auto es considerado de " << automovilMostraGama(movimientoPrueba->factura->automovilVendido) <<
		" gama y tiene unos " << movimientoPrueba->factura->automovilVendido->kmRecorridos <<
		" kms recorridos. El comprador es " << movimientoPrueba->factura->comprador <<
		", quien decidio comprar el vehiculo " << facturaMostraFormaDePago(movimientoPrueba->factura) <<
		", por lo que la factura debe ser tipo " << facturaMostraTipo(movimientoPrueba->factura) <<
		". El valor residual del " << movimientoPrueba->factura->automovilVendido->modelo <<
		" es de $" << movimientoPrueba->factura->automovilVendido->valorResidual <<
		", y Kontarine lo puso a la venta por $" << movimientoPrueba->factura->importe << "." << endl;
}

void movimientoMostraDetalle(Movimiento* movimientoPrueba) {
	cout << endl << "Detalles de Movimiento:" << endl;
	cout << "- Fecha: " << movimientoPrueba->factura->fecha.substr(6, 2) << "/" <<
		movimientoPrueba->factura->fecha.substr(4, 2) << "/" <<
		movimientoPrueba->factura->fecha.substr(0, 4) << endl;
	cout << "- Hora: " << movimientoPrueba->hora << endl;
	cout << "- Mercaderia: " << movimientoPrueba->mercaderia << endl;
	cout << "- Caja: " << movimientoPrueba->caja << endl;
	cout << "- Ventas: " << movimientoPrueba->ventas << endl;
	cout << "- Deudores por Ventas: " << movimientoPrueba->deudoresPorVentas << endl;
	cout << "- Intereses Ganados: " << movimientoPrueba->interesesGanados << endl;
}
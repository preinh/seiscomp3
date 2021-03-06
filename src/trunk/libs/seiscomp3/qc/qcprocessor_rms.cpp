/***************************************************************************
 *   Copyright (C) by GFZ Potsdam                                          *
 *                                                                         *
 *   You can redistribute and/or modify this program under the             *
 *   terms of the SeisComP Public License.                                 *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   SeisComP Public License for more details.                             *
 ***************************************************************************/


#include <seiscomp3/qc/qcprocessor_rms.h>


namespace Seiscomp {
namespace Processing {

IMPLEMENT_SC_CLASS_DERIVED(QcProcessorRms, QcProcessor, "QcProcessorRms");


QcProcessorRms::QcProcessorRms() : QcProcessor() {}

bool QcProcessorRms::setState(const Record *record, const DoubleArray &data) {
	_qcp->parameter = data.rms(data.mean());
	return true;
}

double QcProcessorRms::getRms() {
	try {
		return boost::any_cast<double>(_qcp->parameter);
	}
	catch (const boost::bad_any_cast &) {
		throw Core::ValueException("no data");
	}
}


}
}

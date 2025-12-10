#include <pybind11/pybind11.h>
#include "felix/event_loop.hpp"
#include "felix/datastream.hpp"
#include "felix/tick_record.hpp"

namespace py = pybind11;

PYBIND11_MODULE(felix_engine, m) {
    m.doc() = "Felix HFT Backtester Engine";

    py::class_<felix::TickRecord>(m, "TickRecord")
        .def_readonly("timestamp", &felix::TickRecord::timestamp)
        .def_readonly("symbol_id", &felix::TickRecord::symbol_id)
        .def_readonly("price", &felix::TickRecord::price)
        .def_readonly("volume", &felix::TickRecord::volume)
        .def_readonly("flags", &felix::TickRecord::flags);

    py::class_<felix::DataStream>(m, "DataStream")
        .def(py::init<>())
        .def("load", &felix::DataStream::load);

    py::class_<felix::EventLoop>(m, "EventLoop")
        .def(py::init<>())
        .def("run", [](felix::EventLoop& self, felix::DataStream& stream, py::object strategy) {
            // Trampoline: call strategy.on_tick for each tick
            self.run(stream, [&](const felix::TickRecord& tick) {
                strategy.attr("on_tick")(tick);
            });
        });
}

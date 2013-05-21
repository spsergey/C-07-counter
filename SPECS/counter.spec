Name: count
Version: 1.0
Release: 1%{?dist}
Summary: Программа-счётчик символов
Group: Testing
License: GPL
URL: http://www.lug.mephist.ru
Source0:  %{name}-%{version}.tar.gz
BuildRoot: /tmp/%{name}
BuildRequires: /bin/rm, /bin/mkdir, /bin/cp
Requires: /bin/bash

%description
Программа-счётчик символов: программа подсчитывает количество символов в буфере, полученном через стандартный поток stdin. Программа может в конвейере.
По умолчанию выводит список всех символов в переданном документе. При указании параметра -n или –no-newline не учитывает символы переноса строк, при указании опции -s или –no-spaces не учитывает пробелы и символы табуляции.
Использована библиотека GNU getopt для обработки аргументов командной строки.

%prep

%setup -c %{name}

%build
make

%install
mkdir -p $RPM_BUILD_ROOT/usr/bin
cp %{name} $RPM_BUILD_ROOT/usr/bin

%clean
rm -rf $RPM_BUILD_ROOT

%files
/usr/bin/%{name}

%defattr(-,root,root,-)

#%doc
%attr(0755,root,root)/usr/bin/count

%changelog

* Tue May 21 2013 Ponomarev

- Added /usr/local/bin/count

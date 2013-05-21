Name: counter
Version: 1.0
Release: 1%{?dist}
Summary: Программа-счётчик символов
Group: Testing
License: GPL
URL: http://www.lug.mephist.ru
Source0:  %{name}-%{version}.tar.gz
BuildRoot: %(mktemp -ud %{_tmppath}/%{name}-%{version}-%{release}-XXXXXX)
BuildRequires: /bin/rm, /bin/mkdir, /bin/cp
Requires: /bin/bash

%description
Программа-счётчик символов: программа подсчитывает количество символов в буфере, полученном через стандартный поток stdin. Программа может в конвейере.
По умолчанию выводит список всех символов в переданном документе. При указании параметра -n или –no-newline не учитывает символы переноса строк, при указании опции -s или –no-spaces не учитывает пробелы и символы табуляции.
Использована библиотека GNU getopt для обработки аргументов командной строки.

%prep

%setup -q

%build

#configure

#make %{&_smp_mflags}

%install
rm -rf $RPM_BUILD_ROOT
#make install DESTDIR=$RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/usr/local/bin
cp count $RPM_BUILD_ROOT/usr/local/bin

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root,-)

#%doc
%attr(0755,root,root)/usr/local/bin/count

%changelog

* Tue May 21 2013 Ponomarev

- Added /usr/local/bin/count

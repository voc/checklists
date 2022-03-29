# Checklists template in LaTeX

This is a simple set of LaTex files to produce nice PDF formatted checklists.
You need to have a LaTex environment set up and `xelatex` available.

## Creating a checklist

First create a file called `checklist.tex` on source directory. You can use any name as long the
file has the extension `.tex`.

Here's an example of a simple checklist:

```Tex
\input{preamble.inc}

\begin{document}

\begin{task}
  \begin{checklist}{Nach dem Start}
    \item{Landescheinwerfer}{AUS}
    \item{Landeklappen}{EINGEFAHREN}
    \item{Propeller}{2300 RPM}
    \item{Gemisch}{Verarmt}
  \end{checklist}
\end{task}

\end{document}
```

After this, running `make` should output a PDF file on `pdf/` directory, which
will look similar to this:

![Groceries Checklist](https://raw.githubusercontent.com/mavcunha/checklists/master/img/groceries_checklist.png)

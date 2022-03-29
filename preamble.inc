% vim: ft=tex
\documentclass[10pt, a5paper]{standalone}

\usepackage{booktabs}% def toprule, midrule and etc.
\usepackage[a5paper]{geometry}
\usepackage[cm]{fullpage}
\usepackage{tikz}
\usepackage{environ}
\usepackage{fancyhdr}
\usepackage{amssymb}

\pagestyle{fancy}
\fancyhead{}
\fancyfoot{}
\renewcommand{\headrulewidth}{0pt}
\renewcommand{\footrulewidth}{0pt}

% creates empty checkboxes to be used as the second
% argument to \item on checklist
\newcommand{\checkbox}{\makebox[3ex][r]{\Large{$\square$}}}

% draws a dashed box around to group checklists
% a task has a title, which is the group title
\NewEnviron{task}{\par
\begin{tikzpicture}
\node[rectangle,minimum width=0.9\linewidth] (m)
  {\begin{minipage}{0.85\linewidth}
    \begin{center}\vspace{0.5em}\BODY\end{center}
   \end{minipage}};
\draw[solid](m.south west) rectangle (m.north east);
\end{tikzpicture}\vspace{0.5em}
}

% checklist env sets up a table and format the items.
% in case a item has steps use the \step{asdf}
% command.
\newenvironment{checklist}[1]{%
  \renewcommand{\item}[2]{%
    ##1\hspace{2em}\dotfill\makebox{\uppercase{##2}}\\
  }
  \newcommand{\step}[1]{%
    \hspace*{2em}-\hspace*{\labelsep}##1\\
  }
  \begin{tabular}{p{0.8\linewidth}}
     \toprule
       \multicolumn{1}{c}{\textbf{\uppercase{#1}}}\\
     \midrule
}{\bottomrule\end{tabular}\vspace{1em}}

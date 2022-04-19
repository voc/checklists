% vim: ft=tex
\documentclass[10pt]{article}

\usepackage{booktabs}% def toprule, midrule and etc.
\usepackage[a4paper, twocolumn]{geometry}
\geometry{vmargin=2.5cm, hmargin=0.5cm}
\usepackage{tikz}
\usepackage{environ}
\usepackage{fancyhdr}
\usepackage{xcolor,colortbl}

\pagestyle{fancy}
\renewcommand{\title}[1]{\fancyhead[C]{\textbf{\LARGE{ #1 }}}}
\fancyfoot[C]{\thepage}  

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
    %\textbf{##1}\dotfill\makebox{\textbf{\uppercase{##2}}}\\
    ##1\dotfill\makebox{\uppercase{##2}}\\
  }
  \newcommand{\step}[1]{%
    \hspace*{0.5em}-\hspace*{\labelsep}##1\\
  }
  \begin{tabular}{p{0.8\linewidth}}
       \multicolumn{1}{c}{\cellcolor{black!75}\color{white}\textbf{\uppercase{#1}}}\\
       \vspace{0.25em}
}{\end{tabular}\vspace{1em}}
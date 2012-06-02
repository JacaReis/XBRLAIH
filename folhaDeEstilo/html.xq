<html>
	<head>
		<title>XBRLAIH</title>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8"> </meta>
	</head>
	<body>
<xbrli:xbrl xmlns:n1="http://www.hc.com" xmlns:xlink="http://www.w3.org/1999/xlink" xmlns:xl="http://www.xbrl.org/2003/XLink" xmlns:xbrli="http://www.xbrl.org/2003/instance" xmlns:link="http://www.xbrl.org/2003/linkbase" xmlns:ref="http://www.xbrl.org/2004/ref" xmlns:xbrldt="http://xbrl.org/2005/xbrldt" xmlns:iso4217="http://www.xbrl.org/2003/iso4217">


		<h2>
			Relatório mensal de prévia do faturamento do SISAIH</h2>
		<p>
			Referente ao periodo de {doc($inputDocument)/xbrli:xbrl/xbrli:context/xbrli:period/xbrli:startDate} - {doc($inputDocument)/xbrli:xbrl/xbrli:context/xbrli:period/xbrli:endDate}</p>

		<h6>Procedimentos de Alta Complexidade</h6>
		<table align="left" border="1" cellpadding="1" cellspacing="1" style="width: 500px; ">
			<tbody>
				<tr>
					<td>
						Nome do Investimento</td>
					<td>
						Valor em R$</td>
				</tr>
				<tr>
					<td>
						Atenção Básica (ATB)</td>
					<td>
						{doc($inputDocument)/xbrli:xbrl/n1:valorAltaCAtencaoBasica}</td>
				</tr>
				<tr>
					<td>
						Média e Alta Complexidade (MAC)</td>
					<td>
						{doc($inputDocument)/xbrli:xbrl/n1:valorAltaCMediaAltaComplexidade}</td>
				</tr>
				<tr>
					<td>
						Fundo de Ações Estratégicas e Compensação (FAEC)</td>
					<td>
						{doc($inputDocument)/xbrli:xbrl/n1:valorAltaCFaec}</td>
				</tr>
				<tr>
					<td>
						Total</td>
					<td>
						{doc($inputDocument)/xbrli:xbrl/n1:valorAltaCTotal}</td>
				</tr>
			</tbody>
		</table>
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
		<h6>Procedimentos de Média Complexidade</h6>
		<table border="1" cellpadding="1" cellspacing="1" style="width: 500px; ">
			<tbody>
				<tr>
					<td>
						Nome do Investimento</td>
					<td>
						Valor em R$</td>
				</tr>
				<tr>
					<td>
						Atenção Básica (ATB)</td>
					<td>
						{doc($inputDocument)/xbrli:xbrl/n1:valorMediaCAtencaoBasica}</td>
				</tr>
				<tr>
					<td>
						Média e Alta Complexidade (MAC)</td>
					<td>
						{doc($inputDocument)/xbrli:xbrl/n1:valorMediaCMediaAltaComplexidade}</td>
				</tr>
				<tr>
					<td>
						Fundo de Ações Estratégicas e Compensação (FAEC)</td>
					<td>
						{doc($inputDocument)/xbrli:xbrl/n1:valorMediaCFaec}</td>
				</tr>
				<tr>
					<td>
						Total</td>
					<td>
						{doc($inputDocument)/xbrli:xbrl/n1:valorMediaCTotal}</td>
				</tr>
			</tbody>
		</table>

		<h6>Totais</h6>
		<table border="1" cellpadding="1" cellspacing="1" style="width: 500px; ">
			<tbody>
				<tr>
					<td>
						Nome do Investimento</td>
					<td>
						Valor em R$</td>
				</tr>
				<tr>
					<td>
						Total Atenção Básica (ATB)</td>
					<td>
						{doc($inputDocument)/xbrli:xbrl/n1:totalAtencaoBasica}</td>
				</tr>
				<tr>
					<td>
						Total Média e Alta Complexidade (MAC)</td>
					<td>
						{doc($inputDocument)/xbrli:xbrl/n1:totalMediaAltaComplexidade}</td>
				</tr>
				<tr>
					<td>
						Total Fundo de Ações Estratégicas e Compensação (FAEC)</td>
					<td>
						{doc($inputDocument)/xbrli:xbrl/n1:totalFaec}</td>
				</tr>
				<tr>
					<td>
						Total Geral</td>
					<td>
						{doc($inputDocument)/xbrli:xbrl/n1:totalGeral}</td>
				</tr>
			</tbody>
		</table>
		<p>
			</p>
		<p>

			<em>Relatório gerado usando o software XBRLAIH</em></p>
</xbrli:xbrl>
	</body>
</html>
 
